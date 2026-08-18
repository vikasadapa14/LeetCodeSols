class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0,right=0;
        int ans=0;
        unordered_set<char>charset;
        while(right<n){
            if(charset.find(s[right])==charset.end()){
                charset.insert(s[right]);
                ans=max(ans,right-left+1);
                right++;
            }
            else{
                charset.erase(s[left]);
               left++;
            }
        }
        return ans;
    }
};