#include <stdlib.h>
#include "max_of.h"

int max_of(int x, int y) {
    //char * h = (int *)malloc(sizeof(int) * 1);
    if (x >= y) {
        return x;
    } else {
        return y;
    }
}
