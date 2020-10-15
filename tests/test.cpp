#include "gtest/gtest.h"
extern "C" {
    #include <string.h>
    #include "user_info.h"
    #include "parse_user_email.h"
    #include "memory.h"
    #include "state_t.h"

};
class Foo {
 public:
    Foo(): i(0) {}
    ~Foo() = default;
    int i;
};

class TestFoo : public ::testing::Test {
 protected:
    void SetUp() {
        foo = new Foo;
        foo->i = 5;
    }
    void TearDown() {
        delete foo;
    }
    Foo *foo;
};

TEST(correct_email, test1) {
    char eml[] = "test@mail.ru\0";

    user_info_t *user_info = parse_user_email(eml);

    ASSERT_EQ(1,1);
    EXPECT_TRUE(!strcmp(user_info->user_name, "test"));
    EXPECT_TRUE(!strcmp(user_info->mail_name, "mail"));
    EXPECT_TRUE(!strcmp(user_info->domain, "ru"));

    free_user_info(user_info);
}

TEST(correct_email, test2) {
    char eml[] = "astlok@google.com\0";

    user_info_t *user_info = parse_user_email(eml);

    EXPECT_TRUE(!strcmp(user_info->user_name, "astlok"));
    EXPECT_TRUE(!strcmp(user_info->mail_name, "google"));
    EXPECT_TRUE(!strcmp(user_info->domain, "com"));

    free_user_info(user_info);
}

TEST(incorrect_email, test1) {
    char eml[] = "lsjfa;lsjdf;lksjfofgejfdoodvsjodfsjg\0";

    user_info_t *user_info = parse_user_email(eml);

    EXPECT_TRUE(user_info == nullptr);

}

TEST(incorrect_email, test2) {
    char eml[] = "akddd22342399ccl.";

    user_info_t *user_info = parse_user_email(eml);

    EXPECT_TRUE(user_info == nullptr);

}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
