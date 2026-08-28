class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check if palindrome can be formed
        int odd = 0;
        int mid = -1;

        for (int c = 0; c < 26; c++) {
            if (cnt[c] % 2) {
                odd++;
                mid = c;
            }
        }

        if (odd > 1) {
            return "";
        }

        int m = n / 2;

        // Count characters available for left half
        vector<int> half(26);
        for (int c = 0; c < 26; c++) {
            half[c] = cnt[c] / 2;
        }

        // Build palindrome
        auto build = [&](const string& left) {
            string ans = left;

            if (n % 2) {
                ans += char('a' + mid);
            }

            for (int i = (int)left.size() - 1; i >= 0; i--) {
                ans += left[i];
            }

            return ans;
        };

        /*
         * We construct the left half.
         *
         * First try to make it equal to target's
         * first half.
         */
        string left;
        vector<int> rem = half;

        bool possibleEqual = true;

        for (int i = 0; i < m; i++) {
            int c = target[i] - 'a';

            if (rem[c] == 0) {
                possibleEqual = false;
                break;
            }

            left += target[i];
            rem[c]--;
        }

        /*
         * Case 1:
         * We could construct a left half equal to
         * target's first half.
         *
         * The resulting palindrome might already be
         * greater than target because of the middle/right.
         */
        if (possibleEqual) {
            string candidate = build(left);

            if (candidate > target) {
                return candidate;
            }
        }

        /*
         * Now we need to find the smallest left half
         * that makes the complete palindrome greater.
         *
         * Try increasing a position from right to left.
         */
        for (int i = m - 1; i >= 0; i--) {

            vector<int> available = half;

            // Fix characters before i to target
            bool validPrefix = true;

            for (int j = 0; j < i; j++) {
                int c = target[j] - 'a';

                if (available[c] == 0) {
                    validPrefix = false;
                    break;
                }

                available[c]--;
            }

            if (!validPrefix) {
                continue;
            }

            int cur = target[i] - 'a';

            // Put the smallest character > target[i]
            for (int c = cur + 1; c < 26; c++) {

                if (available[c] == 0) {
                    continue;
                }

                string newLeft = target.substr(0, i);
                newLeft += char('a' + c);

                available[c]--;

                // Fill remaining positions with smallest chars
                for (int x = 0; x < 26; x++) {
                    while (available[x] > 0) {
                        newLeft += char('a' + x);
                        available[x]--;
                    }
                }

                string candidate = build(newLeft);

                if (candidate > target) {
                    return candidate;
                }
            }
        }

        /*
         * Special case for odd length:
         *
         * Left half can be exactly equal to target's
         * left half, but the middle character can be
         * increased.
         *
         * Example:
         * s = "aac"
         * target = "abb"
         *
         * left = "a"
         * middle = 'c'
         *
         * palindrome = "aca" > "abb"
         */
        if (n % 2 && possibleEqual) {
            string candidate = build(left);

            if (candidate > target) {
                return candidate;
            }
        }

        return "";
    }
};