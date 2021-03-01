#include <chrono>
#include <cstdint>
#include <gtest/gtest.h>


template <typename F>
std::chrono::milliseconds measure(F f, int n_measure = 10) {
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < n_measure; i++) {
        f();
    }
    auto end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

TEST(StringBenchmarkTest, foreach_test)
{
    std::vector<int64_t> vec;
    std::string str;
    vec.reserve(100000);
    str.reserve(100000);
    for (int i = 0; i < 100000; ++i) {
        vec.push_back('0');
        str += '0';
    }
    
    int64_t out = 0;
    auto time_vec = measure([&]() {
        out = 0;
        for (auto& x : vec)
        {
            out += x;
        }
    });
    auto time_str = measure([&]() {
        out = 0;
        for (auto& x : str)
        {
            out += int64_t(x);
        }
    });
    EXPECT_GT(time_vec, time_str * 10);
}
