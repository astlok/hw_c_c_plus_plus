#include <stdlib.h>

#include "sequential.h"
#include "utils.h"

int sequential(const char *filename, long size, long result[2]) {
    char *array = (char*)malloc(size * sizeof(char));
    if (array == NULL) {
        return EXIT_FAILURE;
    }
    if (input_array(array, filename, &size) == EXIT_FAILURE) {
        free(array);
        return EXIT_FAILURE;
    }

    if (max_sequence(array, 0, size, result) == EXIT_FAILURE) {
        free(array);
        return EXIT_FAILURE;
    }

    free(array);
    return EXIT_SUCCESS;
}
