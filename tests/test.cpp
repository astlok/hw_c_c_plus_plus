#include "gtest/gtest.h"
extern "C" {
    #include <string.h>
    #include "user_info.h"
    #include "parse_user_email.h"
    #include "memory.h"
    #include "state_t.h"

};

TEST(correct_email, test1) {
    char eml[] = "test@mail.ru\0";

    user_info_t *user_info = parse_user_email(eml);

    EXPECT_EQ(strcmp(user_info->user_name, "test"), 0);
    EXPECT_EQ(strcmp(user_info->mail_name, "mail"), 0);
    EXPECT_EQ(strcmp(user_info->domain, "ru"), 0);

    free_user_info(user_info);
}

TEST(correct_email, test2) {
    char eml[] = "astlok@google.com\0";

    user_info_t *user_info = parse_user_email(eml);

    EXPECT_EQ(strcmp(user_info->user_name, "astlok"), 0);
    EXPECT_EQ(strcmp(user_info->mail_name, "google"), 0);
    EXPECT_EQ(strcmp(user_info->domain, "com"), 0);

    free_user_info(user_info);
}

TEST(incorrect_email, test1) {
    char eml[] = "lsjfa;lsjdf;lksjfofgejfdoodvsjodfsjg\0";

    user_info_t *user_info = parse_user_email(eml);

    EXPECT_EQ(user_info, nullptr);

}

TEST(incorrect_email, test2) {
    char eml[] = "akddd22342399ccl.";

    user_info_t *user_info = parse_user_email(eml);

    EXPECT_EQ(user_info, nullptr);

}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
