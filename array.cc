#pragma once

#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "primitive.cc"

//---code---
template <typename V>
struct Array
{
    Array(Integer capacity)
    {
        this->value.reserve(capacity.value);
    }
    std::string debug_string() const
    {
        std::ostringstream oss;
        this->dump(oss);
        return oss.str();
    }
    template <typename Stream>
    void dump(Stream &stream) const
    {
        for (size_t i = 0; i < this->value.size(); ++i)
        {
            this->value[i].dump(stream);
            if (i != this->value.size() - 1)
            {
                stream << " ";
            }
        }
    }
    std::vector<V> value;
};

/* operators */
template <typename V>
static Bool op_eq(const Array<V> &lhs, const Array<V> &rhs)
{
    if (lhs.value.size() != rhs.value.size())
    {
        return Bool(false);
    }
    for (size_t i = 0; i < lhs.value.size(); ++i)
    {
        if (!op_eq(lhs.value[i], rhs.value[i]).value)
        {
            return Bool(false);
        }
    }
    return Bool(true);
}
template <typename V>
static Bool op_ne(const Array<V> &lhs, const Array<V> &rhs)
{
    return Bool(!op_eq(lhs, rhs).value);
}

/* primitives */
template <typename V>
static Integer size(const Array<V> &container)
{
    return Integer(container.value.size());
}

template <typename V>
static void add(Array<V> &container, const V &value)
{
    container.value.push_back(value);
}

template <typename V>
static const V &at(const Array<V> &container, Integer key)
{
    return container.value.at(key.value);
}
template <typename V>
static void update(Array<V> &container, Integer key, const V &value)
{
    container.value.at(key.value) = value;
}
template <typename V>
static void remove(Array<V> &container, Integer key)
{
    container.value.erase(container.value.begin() + key.value);
}

template <typename V>
static void reverse(Array<V> &container)
{
    std::reverse(container.value.begin(), container.value.end());
}

struct Less {
    template <typename V>
    Bool operator()(const V &lhs, const V &rhs) const {
        return op_lt(lhs, rhs);
    }
};

template <typename V>
static void sort(Array<V> &container)
{
    std::sort(
        container.value.begin(),
        container.value.end(),
        [](const auto &lhs, const auto &rhs) { return op_lt(lhs, rhs).value; });
}
template <typename V, typename F>
static void sort_by(Array<V> &container, F cmp)
{
    std::sort(container.value.begin(), container.value.end(), cmp);
}
