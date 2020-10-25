#ifndef LIB_PARALLEL_PARALLEL_H_
#define LIB_PARALLEL_PARALLEL_H_

#include "segment.h"

int parallel(const char *filename, long size, long result[2]);

int input_segments(segment *segments, const char *array, long child_count, long segment_size, long size);

int segment_processing(char *array, segment *segments, long child_count);

int search_max_sequence(segment *segments, long child_count, long result[2]);

#endif  // LIB_PARALLEL_PARALLEL_H_
