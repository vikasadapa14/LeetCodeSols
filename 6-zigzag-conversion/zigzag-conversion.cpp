class Solution {
public:
    string convert(string s, int numRows) {

        // If only one row, there is no zigzag
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);

        int currentRow = 0;
        int direction = 1;   // 1 = down, -1 = up

        for (char ch : s) {

            // Put character in current row
            rows[currentRow] += ch;

            // If we reach the top, move down
            if (currentRow == 0) {
                direction = 1;
            }

            // If we reach the bottom, move up
            else if (currentRow == numRows - 1) {
                direction = -1;
            }

            // Move to next row
            currentRow += direction;
        }

        // Combine all rows
        string ans = "";

        for (string row : rows) {
            ans += row;
        }

        return ans;
    }
};