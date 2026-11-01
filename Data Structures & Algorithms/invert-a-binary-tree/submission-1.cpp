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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            return root;
        }

        TreeNode* tempLeft = invertTree(root->left);
        TreeNode* tempRight = invertTree(root->right);

        root->left = tempRight;
        root->right = tempLeft;

        return root;
    }
};
