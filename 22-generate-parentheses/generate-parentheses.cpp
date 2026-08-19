class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        backtrack("", 0, 0, n, ans);
        
        return ans;
    }

    void backtrack(string s, int open, int close, int n,
                   vector<string>& ans) {
        
        // We have used all brackets
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // We can add '('
        if (open < n) {
            backtrack(s + "(", open + 1, close, n, ans);
        }

        // We can add ')' only when it is valid
        if (close < open) {
            backtrack(s + ")", open, close + 1, n, ans);
        }
    }
};