//
// Created by vvivi on 9/20/2018.
//
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {

        if (s.empty()) return 0;

        if (none_of(s.begin(), s.end(), [](char c){ return c != ' ';}))
            return 0;

        std::istringstream iss(s);
        std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                         std::istream_iterator<std::string>());
        auto len = results.rbegin()->length();
        return (int)len;
    }
};


TEST(P58, Case1) {
    Solution s;
    ASSERT_EQ(s.lengthOfLastWord("Hello World"), 5);
    ASSERT_EQ(s.lengthOfLastWord("Hello World "), 5);
    ASSERT_EQ(s.lengthOfLastWord("Hello World               "), 5);
    ASSERT_EQ(s.lengthOfLastWord(""), 0);
    ASSERT_EQ(s.lengthOfLastWord("a"), 1);
    ASSERT_EQ(s.lengthOfLastWord("a "), 1);
}

TEST(P58, Case2) {
    Solution s;
    ASSERT_EQ(s.lengthOfLastWord("    "), 0);
}
