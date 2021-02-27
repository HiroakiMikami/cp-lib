#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "input.cc"

TEST(InputTest, read_integer_test) {
    std::stringbuf buf;
    buf.sputn("10\n", 3);
    auto prev = std::cin.rdbuf(&buf);
    EXPECT_EQ(10L, read(Input<Integer>()).value);
    std::cin.rdbuf(prev);
}
TEST(InputTest, read_float_test) {
    std::stringbuf buf;
    buf.sputn("0.0\n", 4);
    auto prev = std::cin.rdbuf(&buf);
    EXPECT_DOUBLE_EQ(0.0, read(Input<Float>()).value);
    std::cin.rdbuf(prev);
}
TEST(InputTest, read_string_test) {
    std::stringbuf buf;
    buf.sputn("10\n", 3);
    auto prev = std::cin.rdbuf(&buf);
    EXPECT_EQ("10", read(Input<String>()).value);
    std::cin.rdbuf(prev);
}
TEST(InputTest, read_array_test) {
    std::stringbuf buf;
    buf.sputn("0 1 2\n", 7);
    auto prev = std::cin.rdbuf(&buf);
    EXPECT_EQ(
        std::vector<Integer>({Integer(0), Integer(1), Integer(2)}),
        read(ArrayInput<Integer>(Integer(3))).value
    );
    std::cin.rdbuf(prev);
}
