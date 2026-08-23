class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int leftSum = 0;
        int rightSum = 0;

        int leftQ = 0;
        int rightQ = 0;

        // Left half
        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        // Right half
        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        // Odd number of '?' -> Alice wins
        if ((leftQ + rightQ) % 2 == 1)
            return true;

        int diff = leftSum - rightSum;

        // Bob wins if this condition is satisfied
        if (diff * 2 == (rightQ - leftQ) * 9)
            return false;

        // Otherwise Alice wins
        return true;
    }
};