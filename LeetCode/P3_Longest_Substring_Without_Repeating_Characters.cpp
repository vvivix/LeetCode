//
// Created by vvivi on 2019/1/25.
//

#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> result{1};

        if (s.length() == 1) return 1;

        for (int i = 1; i < s.length(); i++) {
            auto current = s[i];

            for (int j = i - 1; j >= i - 1 + result[i - 1]; j--) {
                if (current == s[j]) result[i] = 1;
                break;
            }
        }

        transform(s.begin() + 1, s.end(), back_inserter(result),
                  [&result](auto c) {

                      return max(*result.rbegin() + 1, 1);
                  });
        return *max_element(result.begin(), result.end());
    }
};

TEST(P3, Case1) {
    Solution s;
    ASSERT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
    ASSERT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
    ASSERT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
}