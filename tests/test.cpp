#include "gtest/gtest.h"
extern "C" {
    #include "parse_user_eml.h"
};

TEST(test1, max) {
    int x = 7;
    int y = 5;

    int max = max_of(x, y);

    ASSERT_EQ(max, 7);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}