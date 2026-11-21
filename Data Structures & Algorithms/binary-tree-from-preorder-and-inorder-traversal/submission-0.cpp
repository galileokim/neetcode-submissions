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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 && inorder.size() == 0) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        int inOrderIndex;

        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root->val) {
                inOrderIndex = i;
                break;
            }
        }

        vector<int> leftIn(inorder.begin(), inorder.begin() + inOrderIndex);
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + leftIn.size());

        TreeNode* left = buildTree(leftPre, leftIn);

        vector<int> rightIn(inorder.begin() + inOrderIndex + 1, inorder.end());
        vector<int> rightPre(preorder.begin() + 1 + leftPre.size(), preorder.end());

        TreeNode* right = buildTree(rightPre, rightIn);

        root->left = left;
        root->right = right;

        return root;
    }
};
