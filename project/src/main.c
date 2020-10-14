#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.h"
#include "parse_user_eml.h"
#include "user_info_t.h"

int main() {
    puts("Enter your eml:");
    char c = 0;
    char *eml = calloc(1, sizeof(char));
    while (scanf("%c", &c) == 1 && c != '\n') {
        char *tmp = (char*)realloc(eml, (strlen(eml) + 2) * sizeof(char));
        if (tmp == NULL) {
            free(eml);
            return -1;
        }
        eml = tmp;
        strncat(eml, &c, 2);
    }
    user_info_t * user_info = parse_user_eml(eml);
    if (user_info == NULL) {
        free(eml);
        puts("Incorret value");
        return -1;
    }
    free_user_info(user_info);
    free(eml);
    return 0;
}
