class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};

        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        for (int a = 1; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                for (int c = 0; c <= 8; c += 2) {

                    int need[10] = {0};

                    need[a]++;
                    need[b]++;
                    need[c]++;

                    bool possible = true;

                    for (int d = 0; d <= 9; d++) {
                        if (need[d] > freq[d]) {
                            possible = false;
                            break;
                        }
                    }

                    if (possible) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};