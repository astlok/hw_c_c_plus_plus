#include <stdlib.h>

#include "sequential.h"
#include "utils.h"

int sequential(const char *filename, long size, long result[2]) {
    char *array = (char*)malloc(size * sizeof(char));
    if (array == NULL) {
        return -1;
    }
    if (input_array(array, filename, &size) == -1) {
        free(array);
        return -1;
    }

    if (max_sequence(array, 0, size, result) == -1) {
        free(array);
        return -1;
    }

    free(array);
    return 0;
}
