class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target,
                   int start, vector<int>& current) {

        // Target reached
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate values at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no need to continue
            if (candidates[i] > target)
                break;

            // Choose current number
            current.push_back(candidates[i]);

            // i + 1 because each number can be used only once
            backtrack(candidates, target - candidates[i],
                      i + 1, current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> current;

        backtrack(candidates, target, 0, current);

        return result;
    }
};