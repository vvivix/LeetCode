#include <gtest/gtest.h>

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;

        int pre2 = 1, pre1 = 2,cur = 0;

        for (int i = 2; i < n; ++i) {
            cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};

TEST(P70, Case_1) {
    Solution s;
    ASSERT_EQ(s.climbStairs(2), 2);
    ASSERT_EQ(s.climbStairs(3), 3);
    ASSERT_EQ(s.climbStairs(45), 1836311903);
}
