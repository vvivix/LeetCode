//
// Created by vvivi on 9/27/2018.
//
#include <unordered_map>
#include <deque>
#include "gtest/gtest.h"
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

        if (a.size() < b.size())
            swap(a,b);

        bool flag = false;
        string output;
        auto it_a = a.rbegin();
        auto it_b = b.rbegin();
        for (size_t i = 0; i < b.size(); i++) {
            bool f1 = false, f2 = false;
            auto c = add(*it_a, *it_b, f1);
            it_a++;
            it_b++;
            if (flag) c = add(c, '1', f2);
            flag = f1 || f2;
            output = string{c} + output;
        }

        for (size_t i = b.size(); i < a.size(); i++) {
            if (flag) {auto c = add(*it_a, '1', flag); output = string{c} + output; it_a++;}
            else {output = string{*it_a} + output; it_a++;}
        }

        if (flag)
            output = '1' + output;
        return output;
    }

private:
    char add(char a, char b, bool& c) {
        assert(a == '0' || a == '1');
        assert(b == '0' || b == '1');

        if (a == '0' && b == '0') { c = false; return '0';}
        if (a == '0' && b == '1') { c = false; return '1';}
        if (a == '1' && b == '0') { c = false; return '1';}
        if (a == '1' && b == '1') { c = true;  return '0';}
    }
};

TEST(AddBinary, CASE1) {

    Solution s;
    ASSERT_EQ("100", s.addBinary("11", "1"));
    ASSERT_EQ("10101", s.addBinary("1010", "1011"));
    ASSERT_EQ("1000000000000000000", s.addBinary("111111111111111111", "1"));
    ASSERT_EQ("1000000000000000001", s.addBinary("1000000000000000000", "1"));
    ASSERT_EQ("110000000000000000", s.addBinary("101111111111111111", "1"));
}


