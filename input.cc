#pragma once

#include <iostream>

#include "primitive.cc"
#include "array.cc"

//---code---
static void _initialize()
{
    static bool initialized = false;
    if (!initialized)
    {
        std::cin.tie(0);
#ifndef __TEST__
        std::ios_base::sync_with_stdio(false);
#endif
    }
    initialized = true;
}

template <typename V>
struct Input
{
};
template <typename V>
static V read(const Input<V> &x)
{
    _initialize();
    V v;
    std::cin >> v;
    return v;
}
static Integer read(const Input<Integer> &x)
{
    return Integer(read(Input<int64_t>()));
}
static Float read(const Input<Float> &x)
{
    return Float(read(Input<double>()));
}
static String read(const Input<String> &x)
{
    return String(read(Input<std::string>()));
}

template <typename V>
struct ArrayInput
{
    ArrayInput(Integer N) : N(N)
    {
    }
    Integer N;
};

template <typename V>
static Array<V> read(const ArrayInput<V> &x)
{
    Array<V> out(x.N);
    for (int64_t i = 0; i < x.N.value; ++i)
    {
        out.value.push_back(read(Input<V>()));
    }
    return out;
}
