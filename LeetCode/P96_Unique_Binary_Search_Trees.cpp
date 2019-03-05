#include <gtest/gtest.h>

// dp问题
// 考虑到
class Solution {

public:
    int numTrees(int n) {

        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;

        std::vector<int> f;
        f.push_back(1);
        f.push_back(1);
        f.push_back(2);

        while(f.size() != n+1) {
            int cur = static_cast<int>(f.size());
            int v = 0;
            for (int i = 0; i < cur/2; i++) {
                v += 2*f[i]*f[cur-i-1];
            }
            if (cur %2 == 1) {
                v += f[cur/2] * f[cur/2];
            }
            f.push_back(v);
        }

        return f.back();

    }
};

TEST(P96, Case1) {
    Solution s;
    ASSERT_EQ(s.numTrees(0), 0);
    ASSERT_EQ(s.numTrees(1), 1);
    ASSERT_EQ(s.numTrees(2), 2);
    ASSERT_EQ(s.numTrees(3), 5);
    ASSERT_EQ(s.numTrees(4), 14);
}
