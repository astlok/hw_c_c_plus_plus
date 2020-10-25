#ifndef HW_C_PLUS_PLUS_UTILS_H
#define HW_C_PLUS_PLUS_UTILS_H

long file_size(const char *filename);

int input_array(char *array, const char *filename, const long *size);

int max_sequence(const char *array, long begin, long end, long result[2]);
#endif //HW_C_PLUS_PLUS_UTILS_H
