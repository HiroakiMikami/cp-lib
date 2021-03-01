#include "gtest/gtest.h"

#include "integer.cc"

TEST(IntegerTest, integer_as_digit_test) {
    EXPECT_EQ(Integer(1), integer_as_digit(Integer('1')));
}
TEST(IntegerTest, integer_to_lower_order_test) {
    EXPECT_EQ(Integer(1), integer_to_lower_order(Integer('b')));
}
TEST(IntegerTest, integer_to_upper_order_test) {
    EXPECT_EQ(Integer(1), integer_to_upper_order(Integer('B')));
}
