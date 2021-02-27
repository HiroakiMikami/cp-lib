#include <cstdint>
#include <string>
#include "gtest/gtest.h" // lib should not include gtest

//---code---
struct Integer {
    Integer(std::int64_t value) : value(value) {}
    std::int64_t value;

    std::string debug_string() const { return std::to_string(this->value); }
};
struct Float {
    Float(double value) : value(value) {}
    double value;

    std::string debug_string() const { return std::to_string(this->value); }
};
struct String {
    String(std::string value) : value(value) {}
    std::string value;

    std::string debug_string() const { return this->value; }
};
struct Bool {
    Bool(bool value) : value(value) {}
    operator bool() const {
        return this->value;
    }
    bool value;
    std::string debug_string() const { return this->value ? "true" : "false"; }
};

/* operators */
Integer op_add(Integer lhs, Integer rhs) { return Integer{lhs.value + rhs.value}; }
Integer op_sub(Integer lhs, Integer rhs) { return Integer{lhs.value - rhs.value}; }
Integer op_mul(Integer lhs, Integer rhs) { return Integer{lhs.value * rhs.value}; }
Integer op_div(Integer lhs, Integer rhs) { return Integer{lhs.value / rhs.value}; }
Bool op_eq(Integer lhs, Integer rhs) { return Bool(lhs.value == rhs.value); }
Bool op_ne(Integer lhs, Integer rhs) { return Bool(lhs.value != rhs.value); }
Bool op_gt(Integer lhs, Integer rhs) { return Bool(lhs.value > rhs.value); }
Bool op_ge(Integer lhs, Integer rhs) { return Bool(lhs.value >= rhs.value); }
Bool op_lt(Integer lhs, Integer rhs) { return Bool(lhs.value < rhs.value); }
Bool op_le(Integer lhs, Integer rhs) { return Bool(lhs.value <= rhs.value); }
Integer op_mod(Integer lhs, Integer rhs) { return Integer{lhs.value % rhs.value}; }
Integer op_bitand(Integer lhs, Integer rhs) { return Integer{lhs.value & rhs.value}; }
Integer op_bitor(Integer lhs, Integer rhs) { return Integer{lhs.value | rhs.value}; }
Integer op_xor(Integer lhs, Integer rhs) { return Integer{lhs.value ^ rhs.value}; }
Integer op_leftshift(Integer lhs, Integer rhs) { return Integer{lhs.value << rhs.value}; }
Integer op_rightshift(Integer lhs, Integer rhs) { return Integer{lhs.value >> rhs.value}; }

Float op_add(Float lhs, Float rhs) { return Float{lhs.value + rhs.value}; }
Float op_sub(Float lhs, Float rhs) { return Float{lhs.value - rhs.value}; }
Float op_mul(Float lhs, Float rhs) { return Float{lhs.value * rhs.value}; }
Float op_div(Float lhs, Float rhs) { return Float{lhs.value / rhs.value}; }
Bool op_eq(Float lhs, Float rhs) { return Bool(lhs.value == rhs.value); }
Bool op_ne(Float lhs, Float rhs) { return Bool(lhs.value != rhs.value); }
Bool op_gt(Float lhs, Float rhs) { return Bool(lhs.value > rhs.value); }
Bool op_ge(Float lhs, Float rhs) { return Bool(lhs.value >= rhs.value); }
Bool op_lt(Float lhs, Float rhs) { return Bool(lhs.value < rhs.value); }
Bool op_le(Float lhs, Float rhs) { return Bool(lhs.value <= rhs.value); }

Bool op_and(Bool lhs, Bool rhs) { return Bool(lhs.value && rhs.value); }
Bool op_or(Bool lhs, Bool rhs) { return Bool(lhs.value || rhs.value); }
Bool op_eq(Bool lhs, Bool rhs) { return Bool(lhs.value == rhs.value); }
Bool op_ne(Bool lhs, Bool rhs) { return Bool(lhs.value != rhs.value); }

/* cast */
Integer float_to_integer(Float x) { return Integer(int64_t(x.value)); }
Float integer_to_float(Integer x) { return Float(x.value); }
String integer_to_string(Integer x) { return String(std::to_string(x.value)); }
String float_to_string(Float x) { return String(std::to_string(x.value)); } // TODO precision
Integer string_to_integer(String x) { return Integer(std::stoi(x.value)); }
Float string_to_float(const String &x) { return Float(std::stod(x.value)); }

/* range */
struct Range {
    Range(Integer begin, Integer end, Integer step) : begin(begin), end(end), step(step) {}
    Integer begin;
    Integer end;
    Integer step;
};
Range For(Integer b, Integer e) { return Range(b, e, Integer(1)); }
Range ReverseFor(Integer b, Integer e) { return Range(Integer(e.value - 1), Integer(b.value - 1), Integer(-1)); }
Range Rep(Integer N) { return Range(Integer(0), N, Integer(1)); }
Range ReverseRep(Integer N) { return Range(Integer(N.value - 1), Integer(-1), Integer(-1)); }
template <typename F>
void foreach(const Range& r, F f) {
    for (auto i = r.begin.value; i != r.end.value; i += r.step.value) {
        f(i);
    }
}

//---test---
TEST(IntegerTest, debug_string_test) {
    EXPECT_EQ("0", Integer(0).debug_string());
}
TEST(IntegerTest, op_test) {
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

TEST(FloatTest, debug_string_test) {
    EXPECT_EQ("0.000000", Float(0).debug_string());
}
TEST(FloatTest, op_test) {
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

TEST(StringTest, debug_string_test) {
    EXPECT_EQ("foo", String("foo").debug_string());
}

TEST(BoolTest, debug_string_test) {
    EXPECT_EQ("true", Bool(true).debug_string());
    EXPECT_EQ("false", Bool(false).debug_string());
}
TEST(BoolTest, cast_test) {
    EXPECT_TRUE(Bool(true));
    EXPECT_FALSE(Bool(false));
}
TEST(BoolTest, op_test) {
    auto t = Bool(true);
    auto f = Bool(false);
    EXPECT_FALSE(op_eq(t, f));
    EXPECT_TRUE(op_ne(t, f));
    EXPECT_FALSE(op_and(t, f));
    EXPECT_TRUE(op_or(t, f));
}

TEST(PrimitiveTest, cast_test) {
    EXPECT_EQ(0L, float_to_integer(Float(0.5)).value);
    EXPECT_DOUBLE_EQ(0.0, integer_to_float(Integer(0)).value);
    EXPECT_EQ("0", integer_to_string(Integer(0)).value);
    EXPECT_EQ("0.000000", float_to_string(Float(0)).value);
    EXPECT_EQ(0L, string_to_integer(String("0")).value);
    EXPECT_DOUBLE_EQ(0.0, string_to_float(String("0")).value);
}

TEST(RangeTest, foreach_test) {
    std::vector<int64_t> ret;
    foreach(Rep(3), [&](auto i) { ret.push_back(i); });
    EXPECT_EQ(std::vector<int64_t>({0L, 1L, 2L}), ret);

    ret.clear();
    foreach(ReverseRep(3), [&](auto i) { ret.push_back(i); });
    EXPECT_EQ(std::vector<int64_t>({2L, 1L, 0L}), ret);

    ret.clear();
    foreach(For(1, 3), [&](auto i) { ret.push_back(i); });
    EXPECT_EQ(std::vector<int64_t>({1L, 2L}), ret);

    ret.clear();
    foreach(ReverseFor(1, 3), [&](auto i) { ret.push_back(i); });
    EXPECT_EQ(std::vector<int64_t>({2L, 1L}), ret);
}
