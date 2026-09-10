class Solution {
public:

    // Returns {sum, count} for the subtree
    pair<int, int> dfs(TreeNode* root, int& ans) {

        // Empty subtree
        if (root == nullptr) {
            return {0, 0};
        }

        // Get information from left subtree
        pair<int, int> left = dfs(root->left, ans);

        // Get information from right subtree
        pair<int, int> right = dfs(root->right, ans);

        // Calculate current subtree sum
        int sum = root->val + left.first + right.first;

        // Calculate current subtree node count
        int count = 1 + left.second + right.second;

        // Check whether node value == subtree average
        if (root->val == sum / count) {
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {

        int ans = 0;

        dfs(root, ans);

        return ans;
    }
};