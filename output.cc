#include <iostream>
#include <iomanip>

#include "primitive.cc"

//---code---
static void set_precision(Integer x) {
    std::cout << std::fixed << std::setprecision(x.value);
}

template <typename V>
static void print(const V& v) {
    v.dump(std::cout);
    std::cout << std::endl;
}

template <typename V>
static void dump(const V& v) {
    std::cerr << v.debug_string() << std::endl;
}
