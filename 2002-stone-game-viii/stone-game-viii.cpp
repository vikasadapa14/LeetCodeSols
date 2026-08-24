class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Prefix sums
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // If Alice takes all stones
        int ans = stones[n - 1];

        // Try taking first 2, 3, ..., n-1 stones
        for (int i = n - 2; i > 0; i--) {
            ans = max(ans, stones[i] - ans);
        }

        return ans;
    }
};