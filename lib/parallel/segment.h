#ifndef LIB_PARALLEL_SEGMENT_H_
#define LIB_PARALLEL_SEGMENT_H_

typedef struct segment {
    long begin;
    long end;
    int use;
    long max_size;
    long result[2];
} segment;
#endif  // LIB_PARALLEL_SEGMENT_H_
