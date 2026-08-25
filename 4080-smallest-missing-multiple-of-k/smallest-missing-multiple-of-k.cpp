class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        for (int i = 1; ; i++) {
            int n = k * i;

            if (find(nums.begin(), nums.end(), n) == nums.end()) {
                return n;
            }
        }
    }
};