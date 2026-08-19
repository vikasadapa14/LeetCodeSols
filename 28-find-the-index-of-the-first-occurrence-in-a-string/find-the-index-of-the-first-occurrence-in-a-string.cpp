class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.length();
        int m = needle.length();

        for (int i = 0; i <= n - m; i++) {

            int j = 0;

            // Compare needle with haystack starting at i
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            // Entire needle matched
            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};