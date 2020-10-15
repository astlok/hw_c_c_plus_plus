#include <stdlib.h>
#include <string.h>

#include "parse_user_email.h"
#include "state_t.h"
#include "memory.h"

user_info_t *parse_user_email(const char * eml) {
    user_info_t * user_info = (user_info_t*)calloc(1, sizeof(user_info_t));
    if (init_user_info(user_info) == 1) {
        return NULL;
    }

    state_t state = USER_NAME;
    char c[2] = {};
    size_t eml_len = strlen(eml);
    for (int i = 0; i < eml_len; ++i) {
        c[0] = eml[i];
        c[1] = '\0';
        if (c[0] == AT_SIGN) {
            state = MAIL_NAME;
            continue;
        }
        if (c[0] == '.') {
            state = GLOB_DOMAIN;
            continue;
        }
        if (state == USER_NAME) {
            char *tmp = realloc(user_info->user_name, strlen(user_info->user_name) + 2);
            if (tmp == NULL) {
                free_user_info(user_info);
                return NULL;
            }
            user_info->user_name = tmp;
            strncat(user_info->user_name, (const char *) &c, 2);
        }
        if (state == MAIL_NAME) {
            char *tmp = realloc(user_info->mail_name, strlen(user_info->mail_name) + 2);
            if (tmp == NULL) {
                free_user_info(user_info);
                return NULL;
            }
            user_info->mail_name = tmp;
            strncat(user_info->mail_name, (const char *) &c, 2);
        }
        if (state == GLOB_DOMAIN) {
            char *tmp = realloc(user_info->domain, strlen(user_info->domain) + 2);
            if (tmp == NULL) {
                free_user_info(user_info);
                return NULL;
            }
            user_info->domain = tmp;
            strncat(user_info->domain, (const char *) &c, 2);
            if (i == strlen(eml) - 1) {
                state = END;
            }
        }
    }
    if (state != END) {
        free_user_info(user_info);
        return NULL;
    }
    return user_info;
}
