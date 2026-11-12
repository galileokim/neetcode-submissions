/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -2;
    }

    int height(TreeNode* root) {
        if (root == nullptr) {
            return -1;
        }

        int r = height(root->right);
        int l = height(root->left);

        if (r == -2) {
            return -2;
        }

        if (l == -2) {
            return -2;
        }

        if (abs(r - l) > 1) {
            return -2;
        }

        return 1 + max(r, l);
    }
};
