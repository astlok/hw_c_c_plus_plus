#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

long file_size(const char *filename) {
    char path[100];
    snprintf(path, strlen(filename) + 20, "../../tests/%s", filename);
    FILE *file = fopen(path, "r");
    if (!file) {
        return -1;
    }

    long size = 0;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fclose(file);
    return size;
}

int input_array(char *array, const char *filename, const long *size) {
    char path[100];
    snprintf(path, strlen(filename) + 20, "../../tests/%s", filename);
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        return -1;
    }

    for (long i = 0; i < *size; ++i) {
        fscanf(file, "%c", &array[i]);
    }

    fclose(file);
    return 0;
}

int max_sequence(const char *array, long begin, long end, long result[2]) {
    int max = 0;
    int temp_max = 0;
    long first_i = 0;
    long last_i = 0;
    for (long i = begin; i < end; ++i) {
        char ch = array[i];
        if ((ch >= '0') && (ch <= '9')) {
            if (temp_max == 0) {
                first_i = i;
            }
            last_i = i;
            temp_max++;
        } else {
            temp_max = 0;
        }
        if (temp_max > max) {
            result[0] = first_i;
            result[1] = last_i;
            max = temp_max;
        }
    }
    return 0;
}
