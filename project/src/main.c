#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.h"
#include "parse_user_email.h"
#include "user_info.h"

int main() {
    puts("Enter your eml:");
    char c = '\0';

    size_t alloc_mem = 10;
    char *eml = calloc(alloc_mem, sizeof(char));

    size_t cur_lenth_eml = 0;
    while (scanf("%c", &c) == 1 && c != '\n') {
        if (cur_lenth_eml == alloc_mem - 2) {
            alloc_mem *= 2;
            char *tmp = (char*)realloc(eml, alloc_mem * sizeof(char));
            if (tmp == NULL) {
                free(eml);
                return EXIT_FAILURE;
            }
            eml = tmp;
        }
        strncat(eml, &c, 2);
        ++cur_lenth_eml;
    }
    user_info_t * user_info = parse_user_email(eml);
    if (user_info == NULL) {
        free(eml);
        puts("Incorret value");
        return EXIT_FAILURE;
    }
    free_user_info(user_info);
    free(eml);
    return 0;
}
