#include "gtest/gtest.h"

extern "C" {
#include <string.h>
#include "parallel.h"
#include "sequential.h"
#include "utils.h"
};

TEST(test_sequential, test1) {
    const char *filename = "test1.txt";

    long result[2] = {};
    long size = file_size(filename);
    sequential(filename, size, result);
    ASSERT_EQ(result[0], 9);
    ASSERT_EQ(result[1], 21);
}

TEST(test_sequential, test2) {
    const char *filename = "test2.txt";

    long result[2] = {};
    long size = file_size(filename);
    sequential(filename, size, result);
    ASSERT_EQ(result[0], 171);
    ASSERT_EQ(result[1], 191);
}

TEST(test_sequential, test3) {
    const char *filename = "test3.txt";

    long result[2] = {};
    long size = file_size(filename);
    sequential(filename, size, result);
    ASSERT_EQ(result[0], 86);
    ASSERT_EQ(result[1], 102);

}

TEST(test_sequential, test4) {
    const char *filename = "test4.txt";

    long result[2] = {};
    long size = file_size(filename);
    sequential(filename, size, result);
    ASSERT_EQ(result[0], 689674);
    ASSERT_EQ(result[1], 689681);

}

TEST(test_sequential, test5) {
    const char *filename = "test5.txt";

    long result[2] = {};
    long size = file_size(filename);
    sequential(filename, size, result);
    ASSERT_EQ(result[0], 79267);
    ASSERT_EQ(result[1], 79272);
}

TEST(test_sequential, test6) {
    const char *filename = "test6.txt";

    long result[2] = {};
    long size = file_size(filename);
    sequential(filename, size, result);
    ASSERT_EQ(result[0], 8821);
    ASSERT_EQ(result[1], 8826);
}

TEST(test_sequential, test7) {
    const char *filename = "test7.txt";

    long result[2] = {};
    long size = file_size(filename);
    sequential(filename, size, result);
    ASSERT_EQ(result[0], 3379);
    ASSERT_EQ(result[1], 3382);
}

TEST(test_sequential, test8) {
    const char *filename = "test8.txt";

    long result[2] = {};
    long size = file_size(filename);
    sequential(filename, size, result);
    ASSERT_EQ(result[0], 621);
    ASSERT_EQ(result[1], 624);
}

TEST(test_sequential, test9) {
    const char *filename = "test9.txt";

    long result[2] = {};
    long size = file_size(filename);
    sequential(filename, size, result);
    ASSERT_EQ(result[0], 50964361);
    ASSERT_EQ(result[1], 50964369);
}

TEST(test_parallel, test1) {
    const char *filename = "test1.txt";

    long result[2] = {};
    long size = file_size(filename);
    parallel(filename, size, result);
    ASSERT_EQ(result[0], 9);
    ASSERT_EQ(result[1], 21);
}

TEST(test_parallel, test2) {
    const char *filename = "test2.txt";

    long result[2] = {};
    long size = file_size(filename);
    parallel(filename, size, result);
    ASSERT_EQ(result[0], 171);
    ASSERT_EQ(result[1], 191);
}

TEST(test_parallel, test3) {
    const char *filename = "test3.txt";

    long result[2] = {};
    long size = file_size(filename);
    parallel(filename, size, result);
    ASSERT_EQ(result[0], 86);
    ASSERT_EQ(result[1], 102);

}

TEST(test_parallel, test4) {
    const char *filename = "test4.txt";

    long result[2] = {};
    long size = file_size(filename);
    parallel(filename, size, result);
    ASSERT_EQ(result[0], 689674);
    ASSERT_EQ(result[1], 689681);

}

TEST(test_parallel, test5) {
    const char *filename = "test5.txt";

    long result[2] = {};
    long size = file_size(filename);
    parallel(filename, size, result);
    ASSERT_EQ(result[0], 79267);
    ASSERT_EQ(result[1], 79272);
}

TEST(test_parallel, test6) {
    const char *filename = "test6.txt";

    long result[2] = {};
    long size = file_size(filename);
    parallel(filename, size, result);
    ASSERT_EQ(result[0], 8821);
    ASSERT_EQ(result[1], 8826);
}

TEST(test_parallel, test7) {
    const char *filename = "test7.txt";

    long result[2] = {};
    long size = file_size(filename);
    parallel(filename, size, result);
    ASSERT_EQ(result[0], 3379);
    ASSERT_EQ(result[1], 3382);
}

TEST(test_parallel, test8) {
    const char *filename = "test8.txt";

    long result[2] = {};
    long size = file_size(filename);
    parallel(filename, size, result);
    ASSERT_EQ(result[0], 621);
    ASSERT_EQ(result[1], 624);
}

TEST(test_parallel, test9) {
    const char *filename = "test9.txt";

    long result[2] = {};
    long size = file_size(filename);
    parallel(filename, size, result);
    ASSERT_EQ(result[0], 50964361);
    ASSERT_EQ(result[1], 50964369);
}

TEST(stress_test, test) {
    const char *filename = "test_stress.txt";

    long result_parallel[2] = {};
    long result_sequential[2] = {};
    long size = file_size(filename);
    sequential(filename, size, result_sequential);
    parallel(filename, size, result_parallel);
    ASSERT_EQ(result_parallel[0], result_sequential[0]);
    ASSERT_EQ(result_parallel[1], result_sequential[1]);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
