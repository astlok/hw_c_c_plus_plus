#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.h"
#include "parse_user_email.h"
#include "user_info.h"

int main() {
    puts("Enter your eml:");
    char c = '\0';

    int n = 10;
    char *eml = calloc(n, sizeof(char));

    int i = 0;
    while (scanf("%c", &c) == 1 && c != '\n') {
        if (i == n - 2) {
            char *tmp = (char*)realloc(eml, 2 * n * sizeof(char));
            if (tmp == NULL) {
                free(eml);
                return EXIT_FAILURE;
            }
            eml = tmp;
            n *= 2;
        }
        strncat(eml, &c, 2);
        ++i;
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
