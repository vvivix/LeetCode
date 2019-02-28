//
// Created by vvivi on 2019/1/25.
//
#include <gtest/gtest.h>
#include <cmath>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        return (int)sqrt(x);
    }
};

TEST(P69, Case1){
    Solution s;
    ASSERT_EQ(s.mySqrt(4), 2);
    ASSERT_EQ(s.mySqrt(8), 2);
}

const static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();