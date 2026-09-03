class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        bool hasEven = false;
        bool hasOdd = false;

        for (int x : nums1) {
            if (x % 2 == 0) {
                hasEven = true;
            } else {
                hasOdd = true;
                minOdd = min(minOdd, x);
            }
        }

        // All numbers already have the same parity
        if (!hasEven || !hasOdd)
            return true;

        // Try to make everything odd.
        // Every even number must be greater than the smallest odd.
        for (int x : nums1) {
            if (x % 2 == 0 && x <= minOdd)
                return false;
        }

        return true;
    }
};