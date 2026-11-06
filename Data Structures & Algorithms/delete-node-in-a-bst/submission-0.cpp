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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode*& found = find(root, key);

        if (found != nullptr) {
            if (found->right != nullptr && found->left != nullptr) {
                twoChildRemoval(found);
            } else {
                zeroOneChildRemoval(found);
            }
        }

        return root;
    }

    TreeNode*& find(TreeNode*& root, int val) {
        if (root == nullptr) {
            return root;
        }

        if (root->val == val) {
            return root;
        }

        if (root->val > val) {
            return find(root->left, val);
        }

        return find(root->right, val);
    }

    void zeroOneChildRemoval(TreeNode*& root) {
        TreeNode* temp = root;

        if (root->left == nullptr) {
            root = root->right;
        } else {
            root = root->left;
        }

        delete temp;
    }

    void twoChildRemoval(TreeNode*& root) {
        TreeNode*& predNew = iop(root->left);
        TreeNode* pred = predNew;

        predNew = pred->left; // predecessor has no right children
        
        pred->right = root->right;
        pred->left = root->left;

        TreeNode* temp = root;
        root = pred;
        delete temp;
    }

    TreeNode*& iop(TreeNode*& root) {
        if (root->right == nullptr) {
            return root;
        }

        return iop(root->right);
    }
};