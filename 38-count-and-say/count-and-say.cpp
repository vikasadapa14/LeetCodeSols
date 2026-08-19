class Solution {
public:
    string countAndSay(int n) {

        string s = "1";

        for (int i = 2; i <= n; i++) {

            string next = "";

            int j = 0;

            while (j < s.length()) {

                int count = 1;

                // Count consecutive same digits
                while (j + 1 < s.length() &&
                       s[j] == s[j + 1]) {
                    count++;
                    j++;
                }

                // Add count followed by digit
                next += to_string(count);
                next += s[j];

                j++;
            }

            s = next;
        }

        return s;
    }
};