#ifndef HW_C_PLUS_PLUS_PARALLEL_H
#define HW_C_PLUS_PLUS_PARALLEL_H

#include "segment.h"

int parallel(const char *filename, long size, long result[2]);

int input_segments(segment *segments, long child_count, long segment_size, long size);

int segment_processing(char *array, segment *segments, long child_count);

int search_max_sequence(segment *segments, long child_count, long result[2]);

#endif //HW_C_PLUS_PLUS_PARALLEL_H
