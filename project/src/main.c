#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    if (size == -1) {
        return EXIT_FAILURE;
    }

    double start_sequential = clock();

    if (sequential(filename, size, result) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    double finish_sequential = clock();

    printf("Sequential. Time: %lf\n",  (finish_sequential - start_sequential) / CLOCKS_PER_SEC);

    printf("First symbol %ld, last symbol %ld\n", result[0], result[1]);

    result[0] = 0;
    result[1] = 0;

    double start_parallel = clock();

    if (parallel(filename, size, result) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    double finish_parallel = clock();

    printf("Parallel. Time: %lf\n", (finish_parallel - start_parallel) / CLOCKS_PER_SEC);

    printf("First symbol %ld, last symbol %ld\n", result[0], result[1]);

    return EXIT_SUCCESS;
}
