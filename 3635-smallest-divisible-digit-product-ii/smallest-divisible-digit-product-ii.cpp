class Solution {
public:
    string smallestNumber(string num, long long t) {
        // ---- Step 1: factor t into 2^a * 3^b * 5^c * 7^d * rem ----
        int A = 0, B = 0, C = 0, D = 0;
        long long tt = t;
        while (tt % 2 == 0) { tt /= 2; A++; }
        while (tt % 3 == 0) { tt /= 3; B++; }
        while (tt % 5 == 0) { tt /= 5; C++; }
        while (tt % 7 == 0) { tt /= 7; D++; }
        if (tt != 1) return "-1";

        int dv[10][4] = {
            {0,0,0,0}, // 0 unused
            {0,0,0,0}, // 1
            {1,0,0,0}, // 2
            {0,1,0,0}, // 3
            {2,0,0,0}, // 4
            {0,0,1,0}, // 5
            {1,1,0,0}, // 6
            {0,0,0,1}, // 7
            {3,0,0,0}, // 8
            {0,2,0,0}  // 9
        };

        // ---- Step 2: dp[a2][b2][c2][d2] = min digits to cover (a2,b2,c2,d2) ----
        vector<vector<vector<vector<int>>>> dp(
            A+1, vector<vector<vector<int>>>(
                B+1, vector<vector<int>>(
                    C+1, vector<int>(D+1, 0))));

        const int INF = INT_MAX / 2;

        for (int a2 = 0; a2 <= A; a2++) {
            for (int b2 = 0; b2 <= B; b2++) {
                for (int c2 = 0; c2 <= C; c2++) {
                    for (int d2 = 0; d2 <= D; d2++) {
                        if (a2 == 0 && b2 == 0 && c2 == 0 && d2 == 0) {
                            dp[a2][b2][c2][d2] = 0;
                            continue;
                        }
                        int best = INF;
                        for (int dg = 2; dg <= 9; dg++) {
                            int na = max(a2 - dv[dg][0], 0);
                            int nb = max(b2 - dv[dg][1], 0);
                            int nc = max(c2 - dv[dg][2], 0);
                            int nd = max(d2 - dv[dg][3], 0);

                            // FIX: skip transitions that make no progress at all,
                            // otherwise we read an as-yet-uncomputed dp entry
                            // (defaulted to 0) and get a bogus small value.
                            if (na == a2 && nb == b2 && nc == c2 && nd == d2) {
                                continue;
                            }

                            int val = dp[na][nb][nc][nd] + 1;
                            if (val < best) best = val;
                        }
                        dp[a2][b2][c2][d2] = best;
                    }
                }
            }
        }

        auto minDigits = [&](array<int,4> st) -> int {
            return dp[st[0]][st[1]][st[2]][st[3]];
        };

        auto subClamp = [&](array<int,4> st, const int* vec) -> array<int,4> {
            return {
                max(st[0] - vec[0], 0),
                max(st[1] - vec[1], 0),
                max(st[2] - vec[2], 0),
                max(st[3] - vec[3], 0)
            };
        };

        array<int,4> req = {A, B, C, D};
        int n = (int)num.size();

        auto constructSmallest = [&](array<int,4> requirement, int length) -> string {
            string res;
            res.reserve(length);
            array<int,4> state = requirement;
            int remLen = length;
            for (int i = 0; i < length; i++) {
                for (int dg = 1; dg <= 9; dg++) {
                    array<int,4> ns = subClamp(state, dv[dg]);
                    if (minDigits(ns) <= remLen - 1) {
                        res.push_back('0' + dg);
                        state = ns;
                        remLen--;
                        break;
                    }
                }
            }
            return res;
        };

        // ---- Step 3: check num itself ----
        if (num.find('0') == string::npos) {
            array<int,4> exps = {0,0,0,0};
            for (char ch : num) {
                int digit = ch - '0';
                exps[0] += dv[digit][0];
                exps[1] += dv[digit][1];
                exps[2] += dv[digit][2];
                exps[3] += dv[digit][3];
            }
            array<int,4> clamped = subClamp(req, exps.data());
            if (clamped[0]==0 && clamped[1]==0 && clamped[2]==0 && clamped[3]==0) {
                return num;
            }
        }

        // prefix exponent sums
        vector<array<int,4>> prefix(n+1, array<int,4>{0,0,0,0});
        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            prefix[i+1][0] = prefix[i][0] + dv[digit][0];
            prefix[i+1][1] = prefix[i][1] + dv[digit][1];
            prefix[i+1][2] = prefix[i][2] + dv[digit][2];
            prefix[i+1][3] = prefix[i][3] + dv[digit][3];
        }

        int z = (int)num.find('0');
        if (z == -1) z = n;

        string answer = "";
        bool found = false;
        int startI = min(n-1, z);

        for (int i = startI; i >= 0 && !found; i--) {
            array<int,4> pe = prefix[i];
            int baseDigit = num[i] - '0';
            for (int dg = baseDigit + 1; dg <= 9; dg++) {
                array<int,4> newexp = {
                    pe[0] + dv[dg][0],
                    pe[1] + dv[dg][1],
                    pe[2] + dv[dg][2],
                    pe[3] + dv[dg][3]
                };
                array<int,4> remainingReq = subClamp(req, newexp.data());
                int remainingLen = n - 1 - i;
                if (minDigits(remainingReq) <= remainingLen) {
                    string suffix = constructSmallest(remainingReq, remainingLen);
                    answer = num.substr(0, i) + char('0' + dg) + suffix;
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            int L = max(n + 1, minDigits(req));
            answer = constructSmallest(req, L);
        }

        return answer;
    }
};