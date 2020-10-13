#include "gtest/gtest.h"
extern "C" {
    #include "max_of.h"
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