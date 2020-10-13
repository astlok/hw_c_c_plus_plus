#ifndef HW_C_PLUS_PLUS_MEMORY_H
#define HW_C_PLUS_PLUS_MEMORY_H

#include <stdlib.h>

#include "user_info_t.h"

char* increase_data(char *data, size_t length);

int init_user_info(user_info_t *user_info);

void free_user_info(user_info_t *user_info);

#endif //HW_C_PLUS_PLUS_MEMORY_H
