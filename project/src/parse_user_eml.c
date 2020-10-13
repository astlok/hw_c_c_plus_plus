#include <stdlib.h>
#include <string.h>

#include "parse_user_eml.h"
#include "state_t.h"
#include "memory.h"
#include "utils.h"

user_info_t *parse_user_eml(char * eml) {

    state_t state = STATE_USER_NAME;
    user_info_t *user_info = (user_info_t*) calloc(1, sizeof(user_info_t));
    init_user_info(user_info);

    if (init_user_info(user_info)) {
        free_user_info(user_info);
        return NULL;
    }

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
            if (insert(user_info->user_name, &c)) {
                free_user_info(user_info);
                return NULL;
            }
        }
        if (state == STATE_MAIL_NAME) {
            if (insert(user_info->mail_name, &c)) {
                free_user_info(user_info);
                return NULL;
            }
        }
        if (state == STATE_DOMAIN) {
            if (insert(user_info->domain, &c)) {
                return NULL;
            }
        }
    }
    return user_info;
}
