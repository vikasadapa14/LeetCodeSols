class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;

        int minLen = INT_MAX;
        string ans = "";

        for (int right = 0; right < n; right++) {

            // Add current character
            if (s[right] == '1')
                ones++;

            // If we have more than k ones,
            // move left until we have exactly k
            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            // Now window has exactly k ones
            if (ones == k) {

                // Remove leading zeroes because they make
                // the substring longer but don't change #ones
                while (s[left] == '0') {
                    left++;
                }

                int len = right - left + 1;
                string curr = s.substr(left, len);

                // Check shortest first
                if (len < minLen) {
                    minLen = len;
                    ans = curr;
                }
                // Same length -> lexicographically smaller
                else if (len == minLen && curr < ans) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};