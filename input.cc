#pragma once

#include <iostream>

#include "primitive.cc"
#include "array.cc"

//---code---
static void _initialize() {
    static bool initialized = false;
    if (!initialized) {
        std::cin.tie(0);
        #ifndef __TEST__
        std::ios_base::sync_with_stdio(false);
        #endif
    }
    initialized = true;
}

template <typename V>
static V _read() {
    _initialize();
    V v;
    std::cin >> v;
    return v;
}

static Integer read_integer() {
    return Integer(_read<int64_t>());
}
static Float read_float() {
    return Float(_read<double>());
}
static String read_string() {
    return String(_read<std::string>());
}
template <typename V, typename F>
static Array<V> _read_array(Integer N, F read) {
    Array<V> out(N);
    for (int64_t i = 0; i < N.value; ++i) {
        out.value.push_back(read());
    }
    return out;
}

static Array<Integer> read_integer_array(Integer N) {
    return _read_array<Integer>(N, read_integer);
}
static Array<Float> read_float_array(Integer N) {
    return _read_array<Float>(N, read_float);
}
static Array<String> read_string_array(Integer N) {
    return _read_array<String>(N, read_string);
}
