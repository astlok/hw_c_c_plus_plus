#ifndef LIB_PARALLEL_SEGMENT_H_
#define LIB_PARALLEL_SEGMENT_H_

typedef struct segment {
    long begin;
    long end;
    long max_size;
    long result[2];
    int use;
} segment;
#endif  // LIB_PARALLEL_SEGMENT_H_
