#ifndef PROJECT_INCLUDE_MEMORY_H_
#define PROJECT_INCLUDE_MEMORY_H_

#include <stdlib.h>

#include "user_info_t.h"

int init_user_info(user_info_t *user_info);

void free_user_info(user_info_t *user_info);

#endif  // PROJECT_INCLUDE_MEMORY_H_
