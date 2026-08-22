class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<int>& current,
                   vector<bool>& used) {

        // A complete permutation is formed
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        // Try every number
        for (int i = 0; i < nums.size(); i++) {

            // Skip numbers already used
            if (used[i])
                continue;

            // Choose
            current.push_back(nums[i]);
            used[i] = true;

            // Explore
            backtrack(nums, current, used);

            // Undo choice
            used[i] = false;
            current.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, current, used);

        return result;
    }
};