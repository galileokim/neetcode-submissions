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
    bool balanced = true;
    bool isBalanced(TreeNode* root) {
        height(root);

        return balanced;
    }

    int height(TreeNode* root) {
        if (root == nullptr) {
            return -1;
        }

        int r = height(root->right);
        int l = height(root->left);

        if (balanced != false) {
            if (r - l > 1 || r - l < -1) {
                balanced = false;
            }
        }

        return 1 + max(r, l);
    }
};
