#include <cstdint>
#include <string>
#include <sstream>
#include <optional>
#include <iomanip>

//---code---
struct Integer {
    Integer(std::int64_t value) : value(value) {}
    std::int64_t value;

    std::string debug_string() const { return std::to_string(this->value); }
    template <typename Stream>
    void dump(Stream& stream) const { stream << this->value; }
};
struct Float {
    Float(double value) : value(value) {}
    double value;

    std::string debug_string() const { return std::to_string(this->value); }
    template <typename Stream>
    void dump(Stream& stream) const { stream << this->value; }
};
struct String {
    String(std::string value) : value(value) {}
    std::string value;

    std::string debug_string() const { return this->value; }
    template <typename Stream>
    void dump(Stream& stream) const { stream << this->value; }
};
struct Bool {
    Bool(bool value) : value(value) {}
    operator bool() const {
        return this->value;
    }
    bool value;
    std::string debug_string() const {
        std::ostringstream oss;
        this->dump(oss);
        return oss.str();
    }
    template <typename Stream>
    void dump(Stream& stream) const { stream << (this->value ? "true" : "false"); }
};

/* operators */
static Integer op_add(Integer lhs, Integer rhs) { return Integer{lhs.value + rhs.value}; }
static Integer op_sub(Integer lhs, Integer rhs) { return Integer{lhs.value - rhs.value}; }
static Integer op_mul(Integer lhs, Integer rhs) { return Integer{lhs.value * rhs.value}; }
static Integer op_div(Integer lhs, Integer rhs) { return Integer{lhs.value / rhs.value}; }
static Bool op_eq(Integer lhs, Integer rhs) { return Bool(lhs.value == rhs.value); }
static Bool op_ne(Integer lhs, Integer rhs) { return Bool(lhs.value != rhs.value); }
static Bool op_gt(Integer lhs, Integer rhs) { return Bool(lhs.value > rhs.value); }
static Bool op_ge(Integer lhs, Integer rhs) { return Bool(lhs.value >= rhs.value); }
static Bool op_lt(Integer lhs, Integer rhs) { return Bool(lhs.value < rhs.value); }
static Bool op_le(Integer lhs, Integer rhs) { return Bool(lhs.value <= rhs.value); }
static Integer op_mod(Integer lhs, Integer rhs) { return Integer{lhs.value % rhs.value}; }
static Integer op_bitand(Integer lhs, Integer rhs) { return Integer{lhs.value & rhs.value}; }
static Integer op_bitor(Integer lhs, Integer rhs) { return Integer{lhs.value | rhs.value}; }
static Integer op_xor(Integer lhs, Integer rhs) { return Integer{lhs.value ^ rhs.value}; }
static Integer op_leftshift(Integer lhs, Integer rhs) { return Integer{lhs.value << rhs.value}; }
static Integer op_rightshift(Integer lhs, Integer rhs) { return Integer{lhs.value >> rhs.value}; }

static Float op_add(Float lhs, Float rhs) { return Float{lhs.value + rhs.value}; }
static Float op_sub(Float lhs, Float rhs) { return Float{lhs.value - rhs.value}; }
static Float op_mul(Float lhs, Float rhs) { return Float{lhs.value * rhs.value}; }
static Float op_div(Float lhs, Float rhs) { return Float{lhs.value / rhs.value}; }
static Bool op_eq(Float lhs, Float rhs) { return Bool(lhs.value == rhs.value); }
static Bool op_ne(Float lhs, Float rhs) { return Bool(lhs.value != rhs.value); }
static Bool op_gt(Float lhs, Float rhs) { return Bool(lhs.value > rhs.value); }
static Bool op_ge(Float lhs, Float rhs) { return Bool(lhs.value >= rhs.value); }
static Bool op_lt(Float lhs, Float rhs) { return Bool(lhs.value < rhs.value); }
static Bool op_le(Float lhs, Float rhs) { return Bool(lhs.value <= rhs.value); }

static Bool op_and(Bool lhs, Bool rhs) { return Bool(lhs.value && rhs.value); }
static Bool op_or(Bool lhs, Bool rhs) { return Bool(lhs.value || rhs.value); }
static Bool op_eq(Bool lhs, Bool rhs) { return Bool(lhs.value == rhs.value); }
static Bool op_ne(Bool lhs, Bool rhs) { return Bool(lhs.value != rhs.value); }

/* cast */
static Integer float_to_integer(Float x) { return Integer(int64_t(x.value)); }
static Float integer_to_float(Integer x) { return Float(x.value); }
static String integer_to_string(Integer x) { return String(std::to_string(x.value)); }
static String float_to_string(Float x, Integer precision) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision.value);
    oss << x.value;
    return String(oss.str());
}
static Integer string_to_integer(String x) { return Integer(std::stoi(x.value)); }
static Float string_to_float(const String &x) { return Float(std::stod(x.value)); }

/* range */
struct Range {
    Range(Integer begin, Integer end, Integer step) : begin(begin), end(end), step(step) {}
    Integer begin;
    Integer end;
    Integer step;
    std::string debug_string() const {
        std::ostringstream oss;
        this->dump(oss);
        return oss.str();
    }
    template <typename Stream>
    void dump(Stream& stream) const {
        stream << "Range(" << this->begin.value << ":" << this->end.value << ":" << this->step.value << ")";
    }
};
static Range For(Integer b, Integer e) { return Range(b, e, Integer(1)); }
static Range ReverseFor(Integer b, Integer e) { return Range(Integer(e.value - 1), Integer(b.value - 1), Integer(-1)); }
static Range Rep(Integer N) { return Range(Integer(0), N, Integer(1)); }
static Range ReverseRep(Integer N) { return Range(Integer(N.value - 1), Integer(-1), Integer(-1)); }
template <typename F>
static void foreach(const Range& r, F f) {
    for (auto i = r.begin.value; i != r.end.value; i += r.step.value) {
        f(i);
    }
}

/* Optional */
template <typename V>
struct Optional {
    Optional() {}
    Optional(const V& v) : value(v) {}
    std::string debug_string() const {
        std::ostringstream oss;
        this->dump(oss);
        return oss.str();
    }
    template <typename Stream>
    void dump(Stream& stream) const {
        if (this->value) {
            stream << "Some(";
            this->value.value().dump(stream);
            stream << ")";
        } else {
            stream << "nullopt";
        }
    }
    std::optional<V> value;
};

template <typename V>
static Optional<V> AsOptional(const V& v) {
    return Optional(v);
}
template <typename V>
static Bool valid(const Optional<V> &v) {
    return Bool(bool(v.value));
}
template <typename V>
static V from_optional(const Optional<V>& v) {
    return v.value.value();
}
template <typename V, typename F>
static void foreach(const Optional<V>& r, F f) {
    if (valid(r).value) {
        f(r.value.value());
    }
}
