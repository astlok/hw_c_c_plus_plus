#include "memory.h"

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
    if (user_info == NULL) {
        return EXIT_FAILURE;
    }
    user_info->user_name = (char*)calloc(1, sizeof(char));
    if (user_info->user_name == NULL) {
        return EXIT_FAILURE;
    }
    user_info->mail_name = (char*)calloc(1, sizeof(char));
    if (user_info->mail_name == NULL) {
        return EXIT_FAILURE;
    }
    user_info->domain = (char*)calloc(1, sizeof(char));
    if (user_info->domain == NULL) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

