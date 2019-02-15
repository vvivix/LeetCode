//
// Created by vvivi on 1/25/2019.
// source : https://leetcode.com/problems/palindrome-number/
//

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 ) return false;
        if ( x == 0 ) return true;

        vector<int> e_f, f_e;
        while (x) {
            e_f.push_back(x % 10);
            x /= 10;
        }
        copy(e_f.rbegin(), e_f.rend(), back_inserter(f_e));
        return f_e == e_f;
    }
};


TEST(PalindromeNumber, case1) {
    Solution s;
    ASSERT_TRUE(s.isPalindrome(121));
    ASSERT_FALSE(s.isPalindrome(-121));
    ASSERT_FALSE(s.isPalindrome(10));
    ASSERT_TRUE(s.isPalindrome(0));
    ASSERT_TRUE(s.isPalindrome(123454321));
}

