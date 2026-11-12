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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int currMax = maxHeight(root->left) + maxHeight(root->right);
        int leftMax = diameterOfBinaryTree(root->left);
        int rightMax = diameterOfBinaryTree(root->right);

        // memoize

        return max(currMax, max(leftMax, rightMax));
    }

    int maxHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(maxHeight(root->left), maxHeight(root->right));
    }
};
