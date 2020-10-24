#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "sequential.h"
#include "parallel.h"

int main(int argc, char const* argv[]) {
    if (argc < 2) {
        puts("File not transfer");
        return EXIT_FAILURE;
    }
    const char *filename = argv[1];

    long result[2] = {};
    long size = file_size(filename);
    if (size == -1){
        return EXIT_FAILURE;
    }
    if (sequential(filename, size, result) == -1) {
        return EXIT_FAILURE;
    }
    printf("Sequental. First symbol %ld, last symbol %ld\n", result[0], result[1]);

    result[0] = 0;
    result[1] = 0;
    if (parallel(filename, size, result) == -1) {
        return EXIT_FAILURE;
    }
    printf("Parallel. First symbol %ld, last symbol %ld\n", result[0], result[1]);

    return EXIT_SUCCESS;
}
