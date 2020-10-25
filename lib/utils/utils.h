#ifndef LIB_UTILS_UTILS_H_
#define LIB_UTILS_UTILS_H_

long file_size(const char *filename);

int input_array(char *array, const char *filename, const long *size);

int max_sequence(const char *array, long begin, long end, long result[2]);

#endif  // LIB_UTILS_UTILS_H_
