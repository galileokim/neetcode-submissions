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
        return buildTreeRanged(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }

    TreeNode* buildTreeRanged(vector<int>& preorder, vector<int>& inorder, int leftPreBound, int rightPreBound, int leftInBound, int rightInBound) {
        if (leftPreBound == rightPreBound) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[leftPreBound]);
        int inOrderIndex;

        for (int i = leftInBound; i < rightInBound; i++) {
            if (inorder[i] == root->val) {
                inOrderIndex = i;
                break;
            }
        }

        TreeNode* left = buildTreeRanged(preorder, inorder, leftPreBound + 1, leftPreBound + 1 + inOrderIndex - leftInBound, leftInBound, inOrderIndex);

        TreeNode* right = buildTreeRanged(preorder, inorder, leftPreBound + 1 + (inOrderIndex - leftInBound), rightPreBound, inOrderIndex + 1, rightInBound);
    
        root->left = left;
        root->right = right;

        return root;
    }
};
