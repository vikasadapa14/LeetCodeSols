class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.length();

        // Step 1: Ignore leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            sign = 1;
            i++;
        }

        // Step 3: Read digits
        long long num = 0;

        while (i < n && isdigit(s[i])) {

            num = num * 10 + (s[i] - '0');

            // Step 4: Check overflow
            if (sign * num > INT_MAX) {
                return INT_MAX;
            }

            if (sign * num < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return sign * num;
    }
};
