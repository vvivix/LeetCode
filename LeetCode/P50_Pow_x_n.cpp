//
// Created by vvivi on 2019/1/25.
//
#include <gtest/gtest.h>
#include <cmath>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);
    }
};

TEST(P50, Case1) {
    Solution s;
    ASSERT_EQ(s.myPow(2.000, 10), 1024.00000);
    ASSERT_EQ(s.myPow(2.00000, -2), 0.25000);
    ASSERT_EQ(s.myPow(2.10000, 3), 9.26100);

}