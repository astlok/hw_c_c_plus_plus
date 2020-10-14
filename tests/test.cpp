#include "gtest/gtest.h"
extern "C" {
    #include <string.h>
    #include "../project/include/user_info_t.h"
    #include "../project/include/parse_user_eml.h"
    #include "../project/include/memory.h"
    #include "../project/include/state_t.h"

};

TEST(test1, correct_eml) {
    char eml[] = "test@mail.ru\0";

    user_info_t *user_info = parse_user_eml(eml);

    EXPECT_TRUE(!strcmp(user_info->user_name, "test\0"));
    EXPECT_TRUE(!strcmp(user_info->mail_name, "mail\0"));
    EXPECT_TRUE(!strcmp(user_info->domain, "ru\0"));

    free_user_info(user_info);
}

TEST(test2, correct_eml_2) {
    char eml[] = "astlok@google.com\0";

    user_info_t *user_info = parse_user_eml(eml);

    EXPECT_TRUE(!strcmp(user_info->user_name, "astlok\0"));
    EXPECT_TRUE(!strcmp(user_info->mail_name, "google\0"));
    EXPECT_TRUE(!strcmp(user_info->domain, "com\0"));

    free_user_info(user_info);
}

TEST(test3, incorrect_eml) {
    char eml[] = "lsjfa;lsjdf;lksjfofgejfdoodvsjodfsjg\0";

    user_info_t *user_info = parse_user_eml(eml);

    EXPECT_TRUE(user_info == nullptr);

}

TEST(test4, incorrect_eml_2) {
    char eml[] = "akddd22342399ccl.";

    user_info_t *user_info = parse_user_eml(eml);

    EXPECT_TRUE(user_info == nullptr);

}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}