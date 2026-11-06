class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            // we have found the node
            // delete zeroOneChild
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            //two children, find in order predecessor
            TreeNode* iop = root->left;
            while (iop->right) {
                iop = iop->right;
            }

            root->val = iop->val;

            root->left = deleteNode(root->left, iop->val);
        }

        return root;
    } 
};