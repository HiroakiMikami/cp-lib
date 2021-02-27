#pragma once

#include <cmath>

#include "primitive.cc"

static Float sqrt(Float x) {
    return Float(std::sqrt(x.value));
}
template <typename V>
static V max(const V& v0, const V& v1) {
    if (op_lt(v0, v1)) {
        return v1;
    } else {
        return v0;
    }
}
template <typename V>
static V min(const V& v0, const V& v1) {
    if (op_gt(v0, v1)) {
        return v1;
    } else {
        return v0;
    }
}
