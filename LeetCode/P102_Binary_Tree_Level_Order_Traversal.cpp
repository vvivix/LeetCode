//
// Created by vvivi on 10/11/2018.
//

#include "gtest/gtest.h"
#include <deque>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
#if 0 // init version. mark every node's layer. too complex.
        std::deque<pair<TreeNode *, int>> list;
        vector<vector<int>> output{1, vector<int>()};

        if (root == nullptr) return vector<vector<int>>();

        list.emplace_back(make_pair(root, 0));

        while (!list.empty()) {
            auto front = list.front();
            auto cur_hierarchy = front.second;

            if (front.first->left) {
                list.emplace_back(make_pair(front.first->left, front.second + 1));
            }

            if (front.first->right) {
                list.emplace_back(make_pair(front.first->right, front.second + 1));
            }

            if (output.size() <= cur_hierarchy)
                output.emplace_back(vector<int>());
            output[cur_hierarchy].push_back(front.first->val);
            list.pop_front();
        }
        return output;
#else   // scan current layer for output, and enqueue next layer's nodes.
        vector<vector<int>> output;
        if (root == nullptr) return output;

        std::deque<TreeNode *> queue;

        queue.emplace_back(root);

        while (!queue.empty()) {

            output.emplace_back(vector<int>());
            auto it = output.rbegin();
            auto n = queue.size();

            for (int i = 0; i < n; i++) {
                auto front = queue.front();
                queue.pop_front();
                it->push_back(front->val);

                if (front->left) queue.emplace_back(front->left);
                if (front->right) queue.emplace_back(front->right);
            }
        };

        return output;
#endif
    }

};

TEST(P102, case1) {
    auto tree =
            new TreeNode(3,
                         new TreeNode(9, nullptr, nullptr),
                         new TreeNode(20,
                                      new TreeNode(15, nullptr, nullptr),
                                      new TreeNode(7, nullptr, nullptr)
                         )
            );
    vector<vector<int>> expect{{3},
                               {9,  20},
                               {15, 7}};
    Solution s;
    auto result = s.levelOrder(tree);
    ASSERT_EQ(expect, result);
}

TEST(P102, case2) {
    auto tree =
            new TreeNode(3, nullptr, nullptr);

    vector<vector<int>> expect{{3}};
    Solution s;
    auto result = s.levelOrder(tree);
    ASSERT_EQ(expect, result);
}


TEST(P102, case3) {
    TreeNode *tree = nullptr;

    vector<vector<int>> expect{};
    Solution s;
    auto result = s.levelOrder(tree);
    ASSERT_EQ(expect, result);
}