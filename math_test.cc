#include "math.cc"

#include "gtest/gtest.h"

TEST(MathTest, sqrt_test)
{
    EXPECT_DOUBLE_EQ(Float(2.0).value, sqrt(Float(4.0)).value);
}
TEST(MathTest, min_test)
{
    EXPECT_EQ(Integer(0), min(Integer(0), Integer(1)));
    EXPECT_EQ(Integer(0), min(Integer(1), Integer(0)));
}
TEST(MathTest, max_test)
{
    EXPECT_EQ(Integer(1), max(Integer(0), Integer(1)));
    EXPECT_EQ(Integer(1), max(Integer(1), Integer(0)));
}
