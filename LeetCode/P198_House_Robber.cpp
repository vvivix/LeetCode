#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        vector<int> f(nums.size());

        if ( nums.size() == 0 ) return 0;
        if ( nums.size() == 1 ) return nums[0];
        if ( nums.size() == 2 ) return max(nums[0], nums[1]);

        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        f[2] = nums[0] + nums[2];

        for (int i = 3; i < nums.size(); i++) {
            f[i] = max(f[i - 2], f[i - 3]) + nums[i];
        }

        return *max_element(f.begin(), f.end());
    }
};

TEST(P198, case1) {
    Solution s;
    vector<int> input = {1,2,3,1};
    ASSERT_EQ(4, s.rob(input));
}

TEST(P198, case2) {
    Solution s;
    vector<int> input{2,7,9,3,1};
    ASSERT_EQ(12, s.rob(input));
}

TEST(P198, case3) {
    Solution s;
    vector<int> input{};
    ASSERT_EQ(0, s.rob(input));
}

TEST(P198, case4) {
    Solution s;
    vector<int> input{1,8,3};
    ASSERT_EQ(8, s.rob(input));
}