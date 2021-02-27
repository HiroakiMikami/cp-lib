#include "gtest/gtest.h"

#include "output.cc"

TEST(OutputTest, set_precision_test) {
    testing::internal::CaptureStdout();
    set_precision(Integer(2));
    print(Float(0.0));
    auto output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("0.00\n", output);
}

TEST(OutputTest, print_test) {
    testing::internal::CaptureStdout();
    print(Integer(10));
    auto output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("10\n", output);
}

TEST(OutputTest, dump_test) {
    testing::internal::CaptureStderr();
    dump(Integer(10));
    auto output = testing::internal::GetCapturedStderr();
    EXPECT_EQ("10\n", output);
}
