class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target,
                   int index, vector<int>& current) {

        // Target reached
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // No more candidates
        if (index == candidates.size()) {
            return;
        }

        // Choice 1: take current candidate
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);

            // Same index because we can reuse the number
            backtrack(candidates, target - candidates[index],
                      index, current);

            current.pop_back();
        }

        // Choice 2: skip current candidate
        backtrack(candidates, target, index + 1, current);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;

        backtrack(candidates, target, 0, current);

        return result;
    }
};