#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

#include "parallel.h"
#include "utils.h"

int parallel(const char *filename, long size, long result[2]) {
    long child_count = sysconf(_SC_NPROCESSORS_ONLN);
    char *array = (char *) malloc(size * sizeof(char));
    if (array == NULL) {
        return EXIT_FAILURE;
    }
    if (input_array(array, filename, &size) == EXIT_FAILURE) {
        free(array);
        return EXIT_FAILURE;
    }

    long segment_size = size / child_count;
    segment *segments = mmap(NULL, child_count * sizeof(segment), PROT_READ | PROT_WRITE,
                             MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (segments == MAP_FAILED) {
        free(array);
        return EXIT_FAILURE;
    }

    if (input_segments(segments, array, child_count, segment_size, size) == EXIT_FAILURE) {
        free(array);
        return EXIT_FAILURE;
    }

    pid_t pid = fork();
    for (size_t i = 0; i < child_count - 2; ++i) {
        if (pid != 0) {
            pid = fork();
        }
    }

    if (segment_processing(array, segments, child_count) == EXIT_FAILURE) {
        if (pid != 0) {
            munmap(segments, child_count);
            free(array);
            return EXIT_FAILURE;
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
    if (search_max_sequence(segments, child_count, result) == EXIT_FAILURE) {
        munmap(segments, child_count);
        free(array);
        return EXIT_FAILURE;
    }
    munmap(segments, child_count);
    free(array);
    return EXIT_SUCCESS;
}

int input_segments(segment *segments, const char *array, long child_count, long segment_size, long size) {
    for (long i = 0; i < child_count; ++i) {
        long temp_index = 0;
        if (i == 0) {
            segments[i].begin = 0;
            temp_index = segments[i].begin + segment_size - 1;
            while (((array[temp_index] >= '0') && (array[temp_index] <= '9')) && temp_index != size - 1) {
                temp_index++;
            }
            segments[i].end = temp_index;
        } else if (i != child_count - 1) {
            segments[i].begin = segments[i - 1].end + 1;
            while (((array[temp_index] >= '0') && (array[temp_index] <= '9')) && (temp_index != size - 1)) {
                temp_index++;
            }
            segments[i].end = temp_index;
        } else {
            segments[i].begin = segments[i - 1].end + 1;
            segments[i].end = size - 1;
        }
        segments[i].use = 0;
        segments[i].max_size = 0;
    }
    return EXIT_SUCCESS;
}

int segment_processing(char *array, segment *segments, long child_count) {
        for (int i = 0; i < child_count; ++i) {
            if (segments[i].use == 0) {
                segments[i].use = 1;
                if (max_sequence(array,
                                 segments[i].begin,
                                 segments[i].end,
                                 segments[i].result) == EXIT_FAILURE) {
                    return EXIT_FAILURE;
                }
                segments[i].max_size = segments[i].result[1] - segments[i].result[0];
            }
        }
    return EXIT_SUCCESS;
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
    return EXIT_SUCCESS;
}
