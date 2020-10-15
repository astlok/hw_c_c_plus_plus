#include <stdlib.h>
#include <string.h>

#include "parse_user_email.h"
#include "state_t.h"
#include "memory.h"

user_info_t *parse_user_email(const char * eml) {
    user_info_t * user_info = (user_info_t*)calloc(1, sizeof(user_info_t));
    size_t alloc_mem = 10;
    if (init_user_info(user_info, alloc_mem) == 1) {
        return NULL;
    }

    state_t state = USER_NAME;
    char c[2] = {};
    size_t eml_len = strlen(eml);

    size_t alloc_mem_user = alloc_mem;
    size_t alloc_mem_mail = alloc_mem;
    size_t alloc_mem_domain = alloc_mem;

    size_t cur_length_user = 0;
    size_t cur_length_mail = 0;
    size_t cur_length_domain = 0;

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
            if (cur_length_user == alloc_mem_user - 2) {
                alloc_mem_user *= 2;
                char *tmp = realloc(user_info->user_name, alloc_mem_user * sizeof(char));
                if (tmp == NULL) {
                    free_user_info(user_info);
                    return NULL;
                }
                user_info->user_name = tmp;
            }
            strncat(user_info->user_name, (const char *) &c, 2);
            ++cur_length_user;
        }
        if (state == MAIL_NAME) {
            if (cur_length_mail == alloc_mem_mail - 2) {
                alloc_mem_mail *= 2;
                char *tmp = realloc(user_info->mail_name, alloc_mem_mail * sizeof(char));
                if (tmp == NULL) {
                    free_user_info(user_info);
                    return NULL;
                }
                user_info->mail_name = tmp;
            }
            strncat(user_info->mail_name, (const char *) &c, 2);
            ++cur_length_mail;
        }
        if (state == GLOB_DOMAIN) {
            if (cur_length_domain == alloc_mem_domain - 2) {
                alloc_mem_domain *= 2;
                char *tmp = realloc(user_info->domain, alloc_mem_domain * sizeof(char));
                if (tmp == NULL) {
                    free_user_info(user_info);
                    return NULL;
                }
                user_info->domain = tmp;
            }

            strncat(user_info->domain, (const char *) &c, 2);
            ++cur_length_domain;
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
