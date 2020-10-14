#include "gtest/gtest.h"
extern "C" {
    #include <string.h>
    #include "../project/include/user_info_t.h"
    #include "../project/include/parse_user_eml.h"
    #include "../project/include/memory.h"
    #include "../project/include/state_t.h"

};

TEST(test1, eml) {
//    auto * user_info = (user_info_t *)calloc(1, sizeof(user_info_t));
    char eml[] = "test@mail.ru\0";

    user_info_t *user_info = parse_user_eml(eml);

    EXPECT_TRUE(!strcmp(user_info->user_name, "test\0"));
    EXPECT_TRUE(!strcmp(user_info->mail_name, "mail\0"));
    EXPECT_TRUE(!strcmp(user_info->domain, "ru\0"));

    free_user_info(user_info);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}