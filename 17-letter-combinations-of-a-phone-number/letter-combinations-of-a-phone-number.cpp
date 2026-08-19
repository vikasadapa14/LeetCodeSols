class Solution {
public:
    vector<string> result;
    
    string letters[10] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string &digits, int index, string current) {
        // If we used all digits
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get letters corresponding to current digit
        string possible = letters[digits[index] - '0'];

        // Try every possible letter
        for (char ch : possible) {
            current.push_back(ch);

            backtrack(digits, index + 1, current);

            // Undo the choice
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        backtrack(digits, 0, "");

        return result;
    }
};