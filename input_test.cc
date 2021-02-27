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
TEST(InputTest, read_integer_array_test) {
    std::stringbuf buf;
    buf.sputn("0 1 2\n", 7);
    auto prev = std::cin.rdbuf(&buf);
    EXPECT_EQ(
        std::vector<Integer>({Integer(0), Integer(1), Integer(2)}),
        read_integer_array(Integer(3)).value
    );
    std::cin.rdbuf(prev);
}
TEST(InputTest, read_float_array_test) {
    std::stringbuf buf;
    buf.sputn("0 1 2\n", 7);
    auto prev = std::cin.rdbuf(&buf);
    EXPECT_EQ(
        std::vector<Float>({Float(0), Float(1), Float(2)}),
        read_float_array(Integer(3)).value
    );
    std::cin.rdbuf(prev);
}
TEST(InputTest, read_string_array_test) {
    std::stringbuf buf;
    buf.sputn("0 1 2\n", 7);
    auto prev = std::cin.rdbuf(&buf);
    EXPECT_EQ(
        std::vector<String>({String("0"), String("1"), String("2")}),
        read_string_array(Integer(3)).value
    );
    std::cin.rdbuf(prev);
}


