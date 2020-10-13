#include <string.h>

#include "utils.h"
#include "memory.h"

int insert(char * first, char * second) {
    first = increase_data(first, strlen(second) + 1);
    if (first == NULL) {
        return -1;
    }
    strncat(first, second, strlen(second));
    return 0;
}