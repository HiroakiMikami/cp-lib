#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "input.cc"

TEST(InputTest, read_integer_test) {
    std::stringbuf buf;
    buf.sputn("10\n", 3);
    auto prev = std::cin.rdbuf(&buf);
    EXPECT_EQ(10L, read_integer().value);
    std::cin.rdbuf(prev);
}
TEST(InputTest, read_float_test) {
    std::stringbuf buf;
    buf.sputn("0.0\n", 4);
    auto prev = std::cin.rdbuf(&buf);
    EXPECT_DOUBLE_EQ(0.0, read_float().value);
    std::cin.rdbuf(prev);
}
TEST(InputTest, read_string_test) {
    std::stringbuf buf;
    buf.sputn("10\n", 3);
    auto prev = std::cin.rdbuf(&buf);
    EXPECT_EQ("10", read_string().value);
    std::cin.rdbuf(prev);
}

