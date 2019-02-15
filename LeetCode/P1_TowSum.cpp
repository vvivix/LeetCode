//
// Created by vvivi on 9/18/2018.
// @source : https://leetcode.com/problems/two-sum/description/
//

#include <unordered_map>
#include "gtest/gtest.h"
using namespace std;

class Solution {
public:
    /** regular solution.
    vector<int> twoSum(vector<int>& nums, int target) {
        auto  size = nums.size();
        for (int i = 0; i < size ; i++) {
            for ( int j = i+1; j <size; j++) {
                if (nums[i] + nums[j] == target)
                    return {i,j};
            }
        }
    }
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        auto  size = nums.size();
        std::unordered_map<int, int> map{{nums[0], 0}};

        for (auto idx = 1; idx < size; idx++) {
            if (map.find(target - nums[idx]) != map.end())
                return {map[target - nums[idx]], idx};
            map.emplace(nums[idx],idx);
        }

    }
};


TEST(TwoSum, Case1)
{
    vector<int> input{2,7,11,15};
    int taget = 9;
    Solution s;
    auto output = s.twoSum(input, taget);
    ASSERT_EQ(output, vector({0,1}));
}

TEST(TwoSum, Case2)
{
    vector<int> input{99, -1, 2, 9, 7,11,15};
    int taget = 9;
    Solution s;
    auto output = s.twoSum(input, taget);
    ASSERT_EQ(output, vector({2,4}));
}

TEST(TwoSum, Case3)
{
    vector<int> input{3,2,4};
    int taget = 6;
    Solution s;
    auto output = s.twoSum(input, taget);
    ASSERT_EQ(output, vector({1,2}));
}


TEST(TwoSum, Case4)
{
    vector<int> input{3,3};
    int taget = 6;
    Solution s;
    auto output = s.twoSum(input, taget);
    ASSERT_EQ(output, vector({0,1}));
}