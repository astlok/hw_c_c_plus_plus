#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.h"
#include "parse_user_eml.h"
#include "user_info_t.h"

int main() {
    puts("Enter your eml:");

    char *eml =(char*)malloc(sizeof(char));
    char c = 0;
    while (scanf("%c", &c) == 1 && c != '\n') {
        eml = increase_data(eml, sizeof(eml) + sizeof(char));
        strncat(eml, &c, 1);
    }
    user_info_t * user_info = parse_user_eml(eml);
    printf("%s|%s|%s", user_info->user_name, user_info->mail_name, user_info->domain);
    free(eml);
    free_user_info(user_info);
    return 0;
}