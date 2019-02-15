//
// Created by vvivi on 2019/1/25.
//

#include <gtest/gtest.h>
#include <cmath>

using namespace std;


class Solution {
public:
    bool isPerfectSquare(int num) {
        auto r = sqrt(num);
        auto delta = r - (int)r;
        return delta <= 0.0001;
    }
};

TEST(P367, Case1) {
    Solution s;
    ASSERT_TRUE(s.isPerfectSquare(16));
    ASSERT_FALSE(s.isPerfectSquare(14));
}

