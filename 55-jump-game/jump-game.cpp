class Solution {
public:
    bool canJump(vector<int>& nums) {

        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {

            // We cannot reach this index
            if (i > farthest) {
                return false;
            }

            // Update the farthest position we can reach
            farthest = max(farthest, i + nums[i]);

            // We can already reach the last index
            if (farthest >= nums.size() - 1) {
                return true;
            }
        }

        return true;
    }
};