#include <stdlib.h>
#include <string.h>

#include "parse_user_eml.h"
#include "state_t.h"
#include "memory.h"

user_info_t *parse_user_eml(char * eml) {

    user_info_t * user_info = (user_info_t*)calloc(1, sizeof(user_info_t));
    if (init_user_info(user_info) == -1) {
        return NULL;
    }

    state_t state = STATE_USER_NAME;
    char c[2];
    for (int i = 0; i < strlen(eml); ++i) {
        c[0] = eml[i];
        c[1] = '\0';
        if (c[0] == AT_SIGN) {
            state = STATE_MAIL_NAME;
            continue;
        }
        if (c[0] == '.') {
            state = STATE_DOMAIN;
            continue;
        }
        if (state == STATE_USER_NAME) {
            char *tmp = realloc(user_info->user_name, strlen(user_info->user_name) + 2);
            if (tmp == NULL) {
                free(user_info->user_name);
                return NULL;
            }
            user_info->user_name = tmp;
            strncat(user_info->user_name, (const char *) &c, 2);
        }
        if (state == STATE_MAIL_NAME) {
            char *tmp = realloc(user_info->mail_name, strlen(user_info->mail_name) + 2);
            if (tmp == NULL) {
                free(user_info->mail_name);
                return NULL;
            }
            user_info->mail_name = tmp;
            strncat(user_info->mail_name, (const char *) &c, 2);
        }
        if (state == STATE_DOMAIN) {
            char *tmp = realloc(user_info->domain, strlen(user_info->domain) + 2);
            if (tmp == NULL) {
                free(user_info->domain);
                return NULL;
            }
            user_info->domain = tmp;
            strncat(user_info->domain, (const char *) &c, 2);
        }
    }
    return user_info;
}
