//
// Created by vvivi on 10/10/2018.
//

#include <gtest/gtest.h>
using namespace std;



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode sentry(0);
        ListNode* out = &sentry;

        while(l1 && l2) {
            if (l1->val <= l2->val) {
                out->next = l1;
                l1 = l1->next;
            } else {
                out->next = l2;
                l2 = l2->next;
            }
            out = out->next;
        }

        if (l1) {out->next = l1;}
        if (l2) {out->next = l2;}

        return sentry.next;
    }

    bool cmp_list(ListNode* l1, ListNode* l2) {
        while(l1) {
            if (l1->val != l2->val) return false;
            l1 = l1->next; l2 = l2->next;
        }
        return true;
    }
};

TEST(P21, case1) {
    Solution s;
    auto l1 = new ListNode(1, new ListNode(2, new ListNode(4, nullptr)));
    auto l2 = new ListNode(1, new ListNode(3, new ListNode(4, nullptr)));
    auto expect = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(4, nullptr))))));
    auto o = s.mergeTwoLists(l1, l2);
    ASSERT_TRUE(s.cmp_list(o, expect));
}

TEST(P21, case2) {
    Solution s;
    auto l1 = new ListNode(1, new ListNode(2, new ListNode(4, nullptr)));
    auto l2 = nullptr;
    auto expect = l1;
    auto o = s.mergeTwoLists(l1, l2);
    ASSERT_TRUE(s.cmp_list(o, expect));
}

TEST(P21, case3) {
    Solution s;
    ListNode* l1 = nullptr;
    auto l2 = new ListNode(1, new ListNode(3, new ListNode(4, nullptr)));
    auto expect = l2;
    auto o = s.mergeTwoLists(l1, l2);
    ASSERT_TRUE(s.cmp_list(o, expect));
}

TEST(P21, case4) {
    Solution s;
    auto l1 = new ListNode(1, new ListNode(2, new ListNode(4, new ListNode(7, new ListNode(9, new ListNode(11, nullptr))))));
    auto l2 = new ListNode(1, new ListNode(3, new ListNode(4, nullptr)));
    auto expect = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(7, new ListNode(9, new ListNode(11, nullptr)))))))));
    auto o = s.mergeTwoLists(l1, l2);
    ASSERT_TRUE(s.cmp_list(o, expect));
}
