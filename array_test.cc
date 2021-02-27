#include "gtest/gtest.h"

#include "array.cc"

TEST(ArrayTest, constructor_test)
{
    Array<Integer> xs{Integer(2L)};
    EXPECT_EQ(0, xs.value.size());
    EXPECT_EQ(2, xs.value.capacity());
}
TEST(ArrayTest, debug_string_test)
{
    Array<Integer> xs{Integer(2L)};
    add(xs, Integer(0));
    add(xs, Integer(1));
    EXPECT_EQ("0 1", xs.debug_string());
}
TEST(ArrayTest, operator_test) {
    Array<Integer> xs{Integer(2L)};
    Array<Integer> ys{Integer(2L)};
    add(xs, Integer(0));
    EXPECT_FALSE(op_eq(xs, ys).value);
    EXPECT_TRUE(op_ne(xs, ys).value);

    add(ys, Integer(0));
    EXPECT_TRUE(op_eq(xs, ys).value);
    EXPECT_FALSE(op_ne(xs, ys).value);
}

TEST(ArrayTest, primitive_test)
{
    Array<Integer> xs{Integer(2L)};
    add(xs, Integer(0));
    EXPECT_EQ(1, xs.value.size());
    EXPECT_EQ(1, size(xs).value);

    EXPECT_EQ(0, xs.value[0].value);
    EXPECT_EQ(0, at(xs, Integer(0)).value);
    update(xs, Integer(0), Integer(1));
    EXPECT_EQ(1, at(xs, Integer(0)).value);

    remove(xs, Integer(0));
    EXPECT_EQ(0, size(xs).value);
}

TEST(ArrayTest, reverse_test) {
    Array<Integer> xs{Integer(2L)};
    add(xs, Integer(0));
    add(xs, Integer(1));
    reverse(xs);
    EXPECT_EQ(1, xs.value[0].value);
    EXPECT_EQ(0, xs.value[1].value);
}
TEST(ArrayTest, sort_test) {
    Array<Integer> xs{Integer(2L)};
    add(xs, Integer(1));
    add(xs, Integer(0));
    sort(xs);
    EXPECT_EQ(0, xs.value[0].value);
    EXPECT_EQ(1, xs.value[1].value);
}

TEST(ArrayTest, sort_by_test) {
    Array<Integer> xs{Integer(2L)};
    add(xs, Integer(1));
    add(xs, Integer(0));
    auto f = [](auto lhs, auto rhs) {
        return lhs.value > rhs.value;
    };
    sort_by(xs, f);
    EXPECT_EQ(1, xs.value[0].value);
    EXPECT_EQ(0, xs.value[1].value);

    auto g = [](auto lhs, auto rhs) {
        return lhs.value < rhs.value;
    };
    sort_by(xs, g);
    EXPECT_EQ(0, xs.value[0].value);
    EXPECT_EQ(1, xs.value[1].value);
}
