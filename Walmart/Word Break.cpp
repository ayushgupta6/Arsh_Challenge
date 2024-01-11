//link: https://leetcode.com/problems/word-break/description/
class Solution {
public:
    unordered_set<string> st;
    bool memo(int curr, int prev, string &s, vector<vector<int>> &dp){
        if(curr==s.size())
            return prev==s.size();
        
        if(dp[curr][prev]!=-1)
            return dp[curr][prev];
        
        bool ans=0;
        if(st.find(s.substr(prev, curr-prev+1))!=st.end())
            ans = ans || memo(curr+1, curr+1, s, dp);
        ans = ans || memo(curr+1, prev, s, dp);
        return dp[curr][prev]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto i:wordDict)
            st.insert(i);

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return memo(0, 0, s, dp);    
    }
};
