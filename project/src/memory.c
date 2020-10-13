#include "memory.h"

char* increase_data(char *data, size_t length) {
    char *tmp = realloc(data, length * sizeof(char));
    if (tmp == NULL) {
        free(data);
        return NULL;
    }
    return tmp;
}

void free_user_info(user_info_t *user_info) {
    if (user_info == NULL) {
        return;
    }
    free(user_info->user_name);
    free(user_info->mail_name);
    free(user_info->domain);
    free(user_info);
}

int init_user_info(user_info_t *user_info) {
    user_info->user_name = (char*)calloc(1, sizeof(char));
    if (user_info->user_name == NULL) {
        free_user_info(user_info);
        return -1;
    }
    user_info->mail_name = (char*)calloc(1, sizeof(char));
    if (user_info->mail_name == NULL) {
        free_user_info(user_info);
        return -1;
    }
    user_info->domain = (char*)calloc(1, sizeof(char));
    if (user_info->domain == NULL) {
         free_user_info(user_info);
        return -1;
    }
    return 0;
}

