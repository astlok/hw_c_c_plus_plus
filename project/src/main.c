#include <stdio.h>
#include <stdlib.h>
#include "max_of.h"
int main() {
    int x = 0;
    int y = 0;
    scanf("%d%d", &x, &y);
    int max = max_of(x, y);
    printf("Max character is %d", max);
}