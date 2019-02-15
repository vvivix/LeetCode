//
// Created by vvivi on 2019/1/25.
// source : https://leetcode.com/problems/palindrome-linked-list/submissions/
// TODO : Could you do it in O(n) time and O(1) space?
//

#include <gtest/gtest.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        vector<int> v, r;
        while (head) {  v.push_back(head->val); head = head->next; }
        copy(v.rbegin(), v.rend(), back_inserter(r));
        return v == r;
    }
};

TEST(P234, Case1) {
    Solution s;
    auto p1 = make_unique<ListNode>(1);
    auto p2 = make_unique<ListNode>(2);
    p1->next = p2.get();
    ASSERT_FALSE(s.isPalindrome(p1.get()));
}


TEST(P234, Case2) {
    Solution s;
    auto p1 = make_unique<ListNode>(1);
    auto p2 = make_unique<ListNode>(2);
    auto p3 = make_unique<ListNode>(2);
    auto p4 = make_unique<ListNode>(1);
    p1->next = p2.get();
    p2->next = p3.get();
    p3->next = p4.get();
    ASSERT_TRUE(s.isPalindrome(p1.get()));
}

TEST(P234, Case3) {
    Solution s;
    auto p1 = make_unique<ListNode>(1);
    ASSERT_TRUE(s.isPalindrome(p1.get()));
}

