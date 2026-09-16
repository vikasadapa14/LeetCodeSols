class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int sum = 0;

        // Check if left child exists
        if (root->left != nullptr) {

            // Check if left child is a leaf
            if (root->left->left == nullptr &&
                root->left->right == nullptr) {
                sum += root->left->val;
            }
            else {
                sum += sumOfLeftLeaves(root->left);
            }
        }

        // Search right subtree
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};