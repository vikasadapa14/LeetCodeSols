class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Try to make the string greater at position i
        for (int i = n - 1; i >= 0; i--) {

            vector<int> cnt = freq;
            bool possible = true;

            // Use the same prefix as target
            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (cnt[x] == 0) {
                    possible = false;
                    break;
                }

                cnt[x]--;
            }

            if (!possible)
                continue;

            // Find the smallest character greater than target[i]
            int targetChar = target[i] - 'a';

            for (int c = targetChar + 1; c < 26; c++) {

                if (cnt[c] > 0) {

                    string ans = target.substr(0, i);

                    // Put the greater character
                    ans += char('a' + c);
                    cnt[c]--;

                    // Put remaining characters in sorted order
                    for (int x = 0; x < 26; x++) {
                        while (cnt[x] > 0) {
                            ans += char('a' + x);
                            cnt[x]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};