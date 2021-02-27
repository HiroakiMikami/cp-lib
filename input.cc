#include <iostream>

#include "primitive.cc"

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

static Integer read_integer() {
    _initialize();
    int64_t x;
    std::cin >> x;
    return Integer(x);
}
static Float read_float() {
    _initialize();
    double x;
    std::cin >> x;
    return Float(x);
}
static String read_string() {
    _initialize();
    std::string x;
    std::cin >> x;
    return String(x);
}
