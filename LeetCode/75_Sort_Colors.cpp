//
// Created by vvivi on 2019/1/25.
//

#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

TEST(P75, Case1) {
    Solution s;
    vector<int> input {2,0,2,1,1,0};
    s.sortColors(input);
    vector<int> expected {0,0,1,1,2,2};
    ASSERT_EQ(input, expected);
}