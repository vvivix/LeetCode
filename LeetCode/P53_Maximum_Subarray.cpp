//
// Created by vvivi on 9/20/2018.
//

#include <gtest/gtest.h>

using namespace std;

//
// 简单的DP问题
// 标记 [0...n] 区间中,以n结尾的最大子序列为sum[n]
// 则 sum[n] = max{sum[n-1] + num[n], num[n]}
// 最后输出最大的sum[n]即可
//
class Solution {
public:
/*    int maxSubArray(vector<int>& nums) {
        vector<int> sum = {nums[0]};

        for (int i = 1; i < nums.size(); i++) {
            sum.push_back(std::max(sum[i-1] + nums[i], nums[i]));
        }

        int max = INT32_MIN;
        for (auto &a : sum) {
            max = std::max(max, a);
        }
        return max;
    }*/

    /* stl version */
    int maxSubArray(vector<int> &nums) {
        vector<int> sum = {nums[0]};
        transform(nums.begin() + 1, nums.end(), back_inserter(sum),
                  [&sum](auto n) { return max(*sum.rbegin() + n, n); });
        return *max_element(sum.begin(), sum.end());
    }
};

TEST(P53, Case1) {
    vector<int> input{-2,1,-3,4,-1,2,1,-5,4};
    int expect = 6;
    ASSERT_EQ(Solution().maxSubArray(input), expect);
}

TEST(P53, Case2) {
    vector<int> input{-2};
    int expect = -2;
    ASSERT_EQ(Solution().maxSubArray(input), expect);
}