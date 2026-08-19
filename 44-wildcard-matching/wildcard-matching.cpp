class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.length();
        int m = p.length();

        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(m + 1, false)
        );

        // Empty string matches empty pattern
        dp[0][0] = true;

        // Initialize first row
        // Only '*' can match an empty string
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // Normal character or '?'
                if (p[j - 1] == '?' ||
                    p[j - 1] == s[i - 1]) {

                    dp[i][j] = dp[i - 1][j - 1];
                }

                // '*'
                else if (p[j - 1] == '*') {

                    dp[i][j] =
                        dp[i][j - 1] ||     // '*' matches empty
                        dp[i - 1][j];       // '*' matches one/more
                }
            }
        }

        return dp[n][m];
    }
};