#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "segment.h"
#include "parallel.h"
#include "utils.h"
#include <sys/mman.h>
//TODO: заменить на sysinfo при отправке на удаленный сервер
//#include <sys/sysctl.h>

int parallel(const char *filename, long size, long result[2]) {
    long child_count = sysconf(_SC_NPROCESSORS_ONLN);
    char *array = (char *) malloc(size * sizeof(char));
    if (array == NULL) {
        return -1;
    }
    if (input_array(array, filename, &size) == -1) {
        free(array);
        return -1;
    }

    long segment_size = size / child_count;
    segment *segments = mmap(NULL, child_count * sizeof(segment), PROT_READ | PROT_WRITE,
                             MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (segments == MAP_FAILED) {
        free(array);
        return -1;
    }

    if (input_segments(segments, child_count, segment_size, size) == -1) {
        free(array);
        return -1;
    }

    pid_t pid = fork();
    for (size_t i = 0; i < child_count - 2; ++i) {
        if (pid != 0) {
            pid = fork();
        }
    }

    if (segment_processing(array, segments, child_count) == -1) {
        if (pid != 0) {
            munmap(segments, child_count);
            free(array);
            return -1;
        } else {
            exit(EXIT_FAILURE);
        }
    } else if (pid == 0) {
        exit(EXIT_SUCCESS);
    }

    int status = 0;
    if (pid > 0) {
        for (int i = 0; i < child_count - 1; ++i) {
            wait(&status);
            if (status == -1) {
                puts("Process error");
            }
        }
    }
    if (search_max_sequence(segments, child_count, result) == -1) {
        munmap(segments, child_count);
        free(array);
        return -1;
    }
    munmap(segments, child_count);
    free(array);
    return 0;
}

int input_segments(segment *segments, long child_count, long segment_size, long size) {
    for (long i = 0; i < child_count; ++i) {
        if (i == 0) {
            segments[i].begin = 0;
            segments[i].end = segments[i].begin + segment_size - 1;
        } else if (i != child_count - 1) {
            segments[i].begin = segments[i - 1].end + 1;
            segments[i].end = segments[i].begin + segment_size - 1;
        } else {
            segments[i].begin = segments[i - 1].end + 1;
            segments[i].end = size - 1;
        }
        segments[i].use = 0;
        segments[i].max_size = 0;
    }
    return 0;
}

int segment_processing(char *array, segment *segments, long child_count) {
        for (int i = 0; i < child_count; ++i) {
            if (segments[i].use == 0) {
                segments[i].use = 1;
                if (max_sequence(array, segments[i].begin, segments[i].end, segments[i].result) == -1) {
                    return -1;
                }
                segments[i].max_size = segments[i].result[1] - segments[i].result[0];
            }
        }
    return 0;
}

int search_max_sequence(segment *segments, long child_count, long result[2]) {
    long max = 0;
    for (long i = 0; i < child_count; ++i) {
        if (segments[i].max_size > max) {
            max = segments[i].max_size;
            result[0] = segments[i].result[0];
            result[1] = segments[i].result[1];
        }
    }
    return 0;
}












