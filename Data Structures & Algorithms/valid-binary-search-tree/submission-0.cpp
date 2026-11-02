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
    bool isValidBST(TreeNode* root) {
        return rangeSearch(root, -1000000001, 1000000001);
    }

    bool rangeSearch(TreeNode* root, long min, long max) {
        if (root == nullptr) {
            return true;
        }

        if (root->val < min || root->val > max) {
            return false;
        }

        return rangeSearch(root->left, min, root->val) && rangeSearch(root->right, root->val, max);
    }

};
