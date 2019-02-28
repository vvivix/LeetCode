#include <gtest/gtest.h>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define RECURSIVE 0
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
#if RECURSIVE
    void recursive(TreeNode* root, vector<int>& order) {
        if (!root)
            return;
        if (root->left)
            recursive(root->left, order);
        order.push_back(root->val);
        if (root->right)
            recursive(root->right, order);
    }
#else
    void iterative(TreeNode* root, vector<int>& order) {
        stack<TreeNode*> s;
        TreeNode* it = root;
        if (root == nullptr)
            return;
        while (true) {
            // go through left child first
            // push father node to stack
            if (it->left) {
                s.push(it);
                it = it->left;
                continue;
            }

            // Now, there is not left child for current node.
            order.push_back(it->val);

            // locate a node with right child
            while (!s.empty()) {
                if (it->right) {
                    break;
                }
                it = s.top();
                s.pop();
                order.push_back(it->val);
            }

            if (s.empty() && it->right == nullptr)
                return;

            it = it->right;
        }
    }

#endif

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
#if RECURSIVE
        recursive(root, output);
#else
        iterative(root, output);
#endif
        return output;
    }
};

const static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

TEST(P94, Case1) {
    vector<int> expect{1, 3, 2};
    auto root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution s;
    auto result = s.inorderTraversal(root);
    ASSERT_EQ(result, expect);
}

TEST(P94, Case2) {
    vector<int> expect{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);
    root->right->right = new TreeNode(9);
    Solution s;
    auto result = s.inorderTraversal(root);
    ASSERT_EQ(result, expect);
}

TEST(P94, Case3) {
    vector<int> expect{1, 2, 3};
    auto root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    Solution s;
    auto result = s.inorderTraversal(root);
    ASSERT_EQ(result, expect);
}

TEST(P94, Case4) {
    //    [3,1,2]
    vector<int> expect{1, 3, 2};
    auto root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    Solution s;
    auto result = s.inorderTraversal(root);
    ASSERT_EQ(result, expect);
}