class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(s.size() + 1, 0);

        dp[0] = 1;  
        vector<long long> last(26, 0);

        for (int i = 1; i <= s.size(); i++) {
            int c = s[i - 1] - 'a';

            dp[i] = (2 * dp[i - 1] - last[c] + MOD) % MOD;

            last[c] = dp[i - 1];
        }

        return (dp[s.size()] - 1 + MOD) % MOD;
    }
};