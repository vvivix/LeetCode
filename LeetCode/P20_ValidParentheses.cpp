//
// Created by vvivi on 11/5/2018.
//

#include <gtest/gtest.h>
#include <stack>
using namespace std;


class Solution {

public:
    bool isValid(string s) {
        if (s.empty()) return true;

        stack<char> stk;

        for (auto& c : s) {
            if ( isClosureChar(c) && stk.empty() )
                return false;

            if ( !stk.empty() && stk.top() == pairOf(c) )
                stk.pop();
            else
                stk.push(c);
        }

        return stk.empty();
    }

private:
    static inline char isClosureChar(char c) { return c == ')' || c == '}' || c  == ']'; }

    char pairOf(char c) {
        if (c == ')') return '(';
        if (c == '}') return '{';
        if (c == ']') return '[';
        return (char)-1;
    }
};


TEST(P20, case1) {
    Solution s;
    string input = "()";
    ASSERT_EQ(s.isValid(input), true);
}

TEST(P20, case2) {
    Solution s;
    string input = "()[]{}";
    ASSERT_EQ(s.isValid(input), true);
}

TEST(P20, case3) {
    Solution s;
    string input = "(]";
    ASSERT_EQ(s.isValid(input), false);
}

TEST(P20, case4) {
    Solution s;
    string input = "([)]";
    ASSERT_EQ(s.isValid(input), false);
}

TEST(P20, case5) {
    Solution s;
    string input = "{[]}";
    ASSERT_EQ(s.isValid(input), true);
}

TEST(P21, case6) {
    Solution s;
    string input = "";
    ASSERT_EQ(s.isValid(input), true);
}