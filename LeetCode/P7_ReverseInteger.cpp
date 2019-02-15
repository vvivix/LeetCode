//
// Created by vvivi on 9/19/2018.
// source : https://leetcode.com/problems/reverse-integer/description/
//

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool negative = x < 0;
        int input = abs(x);
        uint64_t output = 0; // key to avoid overflow

        while(input != 0) {
            auto tmp = input % 10;
            input /= 10;
            output = output * 10 + tmp;
        }
        if (output > INT32_MAX)
            return 0;
        return negative ? -(int)output : (int)output;
    }
};

TEST(ReverseInteger, case1)
{
    Solution s;
    ASSERT_EQ(s.reverse(123), 321);
    ASSERT_EQ(s.reverse(-123), -321);
    ASSERT_EQ(s.reverse(120), 21);
    ASSERT_EQ(s.reverse(0), 0);
    ASSERT_EQ(s.reverse(-12345678), -87654321);
    ASSERT_EQ(s.reverse(1534236469), 0);
    ASSERT_EQ(s.reverse(-2147483648), 0);
}