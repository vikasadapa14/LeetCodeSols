class Solution {
public:
    bool isMatch(string s, string p) {

        int m = s.length();
        int n = p.length();

        vector<vector<bool>> dp(m + 1,
                                vector<bool>(n + 1, false));

        // Empty string matches empty pattern
        dp[0][0] = true;

        // Handle patterns like a*, a*b*, a*b*c*
        for (int j = 2; j <= n; j++) {

            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; i++) {

            for (int j = 1; j <= n; j++) {

                // Case 1: Normal character or '.'
                if (p[j - 1] == '.' ||
                    p[j - 1] == s[i - 1]) {

                    dp[i][j] = dp[i - 1][j - 1];
                }

                // Case 2: '*'
                else if (p[j - 1] == '*') {

                    // Option 1: '*' matches zero characters
                    dp[i][j] = dp[i][j - 2];

                    // Option 2: '*' matches one or more
                    if (p[j - 2] == '.' ||
                        p[j - 2] == s[i - 1]) {

                        dp[i][j] =
                            dp[i][j] ||
                            dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};