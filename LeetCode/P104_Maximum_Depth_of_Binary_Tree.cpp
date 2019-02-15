//
// Created by vvivi on 9/28/2018.
//

#include "gtest/gtest.h"

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
#if 0 // a more elegance solution.
    int maxDepth(TreeNode* root) {
        return root == nullptr ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
#endif

    int maxDepth(TreeNode* root) {

        if (root == nullptr) return 0;
        visitTree(root, 1);
        return max_depth;
    }

private:
    int max_depth = 0;
    void visitTree(TreeNode* node, int cur_depth) {
        if (node == nullptr) {
            return;
        }

        max_depth = max(max_depth, cur_depth);

        if (node->left)
            visitTree(node->left, cur_depth+1);
        if (node->right)
            visitTree(node->right, cur_depth+1);
    }
};

TEST(maxDepth, case1) {
    TreeNode node = {
            3,
            new TreeNode{9,
                         nullptr,
                         nullptr},
            new TreeNode {20,
                          new TreeNode{15,
                                       nullptr,
                                       nullptr},
                          new TreeNode{7,
                                       nullptr,
                                       nullptr}}
    };

    ASSERT_EQ(3, Solution().maxDepth(&node));
}