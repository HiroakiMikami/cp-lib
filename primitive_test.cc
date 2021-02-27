#include "primitive.cc"
#include "gtest/gtest.h"

//---test---
TEST(IntegerTest, debug_string_test)
{
    EXPECT_EQ("0", Integer(0).debug_string());
}
TEST(IntegerTest, op_test)
{
    auto one = Integer(1);
    auto two = Integer(2);
    EXPECT_EQ(3, op_add(one, two).value);
    EXPECT_EQ(-1, op_sub(one, two).value);
    EXPECT_EQ(2, op_mul(one, two).value);
    EXPECT_EQ(0, op_div(one, two).value);
    EXPECT_FALSE(op_eq(one, two).value);
    EXPECT_TRUE(op_ne(one, two).value);
    EXPECT_FALSE(op_gt(one, two).value);
    EXPECT_FALSE(op_ge(one, two).value);
    EXPECT_TRUE(op_lt(one, two).value);
    EXPECT_TRUE(op_le(one, two).value);
    EXPECT_EQ(0, op_mod(two, one).value);
    EXPECT_EQ(0, op_bitand(two, one).value);
    EXPECT_EQ(3, op_bitor(two, one).value);
    EXPECT_EQ(3, op_xor(two, one).value);
    EXPECT_EQ(4, op_leftshift(two, one).value);
    EXPECT_EQ(1, op_rightshift(two, one).value);
}

TEST(FloatTest, debug_string_test)
{
    EXPECT_EQ("0.000000", Float(0).debug_string());
    EXPECT_EQ("0.000001", Float(1e-6).debug_string());
}
TEST(FloatTest, op_test)
{
    auto one = Float(1);
    auto two = Float(2);
    EXPECT_DOUBLE_EQ(3, op_add(one, two).value);
    EXPECT_DOUBLE_EQ(-1, op_sub(one, two).value);
    EXPECT_DOUBLE_EQ(2, op_mul(one, two).value);
    EXPECT_DOUBLE_EQ(0.5, op_div(one, two).value);
    EXPECT_FALSE(op_eq(one, two).value);
    EXPECT_TRUE(op_ne(one, two).value);
    EXPECT_FALSE(op_gt(one, two).value);
    EXPECT_FALSE(op_ge(one, two).value);
    EXPECT_TRUE(op_lt(one, two).value);
    EXPECT_TRUE(op_le(one, two).value);
}

TEST(StringTest, debug_string_test)
{
    EXPECT_EQ("foo", String("foo").debug_string());
}

TEST(BoolTest, debug_string_test)
{
    EXPECT_EQ("true", Bool(true).debug_string());
    EXPECT_EQ("false", Bool(false).debug_string());
}
TEST(BoolTest, cast_test)
{
    EXPECT_TRUE(Bool(true));
    EXPECT_FALSE(Bool(false));
}
TEST(BoolTest, op_test)
{
    auto t = Bool(true);
    auto f = Bool(false);
    EXPECT_FALSE(op_eq(t, f));
    EXPECT_TRUE(op_ne(t, f));
    EXPECT_FALSE(op_and(t, f));
    EXPECT_TRUE(op_or(t, f));
}

TEST(PrimitiveTest, cast_test)
{
    EXPECT_EQ(0L, float_to_integer(Float(0.5)).value);
    EXPECT_DOUBLE_EQ(0.0, integer_to_float(Integer(0)).value);
    EXPECT_EQ("0", integer_to_string(Integer(0)).value);
    EXPECT_EQ("0.000000", float_to_string(Float(0), 6).value);
    EXPECT_EQ("0.0", float_to_string(Float(0), 1).value);
    EXPECT_EQ(0L, string_to_integer(String("0")).value);
    EXPECT_DOUBLE_EQ(0.0, string_to_float(String("0")).value);
}

TEST(RangeTest, debug_string_test)
{
    EXPECT_EQ("Range(0:1:1)", Range(Integer(0), Integer(1), Integer(1)).debug_string());
}
TEST(RangeTest, foreach_test)
{
    std::vector<int64_t> ret;
    foreach (Rep(3), [&](auto i) { ret.push_back(i); })
        ;
    EXPECT_EQ(std::vector<int64_t>({0L, 1L, 2L}), ret);

    ret.clear();
    foreach (ReverseRep(3), [&](auto i) { ret.push_back(i); })
        ;
    EXPECT_EQ(std::vector<int64_t>({2L, 1L, 0L}), ret);

    ret.clear();
    foreach (For(1, 3), [&](auto i) { ret.push_back(i); })
        ;
    EXPECT_EQ(std::vector<int64_t>({1L, 2L}), ret);

    ret.clear();
    foreach (ReverseFor(1, 3), [&](auto i) { ret.push_back(i); })
        ;
    EXPECT_EQ(std::vector<int64_t>({2L, 1L}), ret);
}

TEST(OptionalTest, constructor_test)
{
    Optional<Integer> x;
    EXPECT_FALSE(x.value);
}
TEST(OptionalTest, as_optional_test)
{
    Optional<Integer> x = AsOptional(Integer(0));
    EXPECT_TRUE(x.value);
    EXPECT_EQ(0, x.value.value().value);
}
TEST(OptionalTest, debug_string_test)
{
    Optional<Integer> x;
    EXPECT_EQ("nullopt", x.debug_string());
    x = AsOptional(Integer(0));
    EXPECT_EQ("Some(0)", x.debug_string());
}
TEST(OptionalTest, foreach_test)
{
    Optional<Integer> x;
    bool called = false;
    foreach(x, [&](auto x) {
        called = true;
    });
    EXPECT_FALSE(called);
    x = AsOptional(Integer(0));
    foreach(x, [&](auto x) {
        called = true;
    });
    EXPECT_TRUE(called);
}
