#ifndef HW_C_PLUS_PLUS_SEGMENT_H
#define HW_C_PLUS_PLUS_SEGMENT_H

typedef struct segment {
    long begin;
    long end;
    int use;
    long max_size;
    long result[2];
} segment;
#endif //HW_C_PLUS_PLUS_SEGMENT_H
