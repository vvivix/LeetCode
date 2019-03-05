#include <gtest/gtest.h>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void travelTree(TreeNode* root, std::vector<int>& q) {
        if (root == nullptr)
            return;
        if (root->left)
            travelTree(root->left, q);
        q.push_back(root->val);
        if (root->right)
            travelTree(root->right, q);
    }

public:
    bool isValidBST(TreeNode* root) {
        std::vector<int> q;
        travelTree(root, q);
        int64_t max = INT64_MIN;
        // 二叉搜索树必定是一个递增序列.
        for (auto& v : q) {
            if (v > max)
                max = v;
            else
                return false;
        }
        return true;
    }
};

TEST(P98, Case_1) {
    auto root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    Solution s;
    ASSERT_TRUE(s.isValidBST(root));
}

TEST(P98, Case_2) {
    auto root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    Solution s;
    ASSERT_FALSE(s.isValidBST(root));
}

TEST(P98, Case_3) {
    auto root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    Solution s;
    ASSERT_FALSE(s.isValidBST(root));
}

TEST(P98, Case_4) {
    auto root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(8);

    Solution s;
    ASSERT_FALSE(s.isValidBST(root));
}

TEST(P98, Case_5) {
    auto root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(20);

    Solution s;
    ASSERT_FALSE(s.isValidBST(root));
}

TEST(P98, Case_6) {
    auto root = new TreeNode(INT32_MIN);
    Solution s;
    ASSERT_TRUE(s.isValidBST(root));
}

TEST(P98, Case_7) {
    auto root = new TreeNode(0);
    Solution s;
    ASSERT_TRUE(s.isValidBST(root));
}