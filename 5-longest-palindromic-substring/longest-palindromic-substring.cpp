class Solution {
public:

    string longestPalindrome(string s) {

        int n = s.length();

        int start = 0;
        int maxLen = 1;

        for (int center = 0; center < n; center++) {

            // Odd length palindrome
            int left = center;
            int right = center;

            while (left >= 0 && right < n &&
                   s[left] == s[right]) {

                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }

                left--;
                right++;
            }


            // Even length palindrome
            left = center;
            right = center + 1;

            while (left >= 0 && right < n &&
                   s[left] == s[right]) {

                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }

                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};