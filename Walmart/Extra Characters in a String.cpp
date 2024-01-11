//link:https://leetcode.com/problems/extra-characters-in-a-string/description/
class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {  
        unordered_set<string> dic;
        for(auto i:dict)
            dic.insert(i);

        int n=s.size();
        vector<int> dp(n+1, 0);

        for(int i=n-1;i>=0; i--){
            dp[i]  = 1+dp[i+1];
            for(int j=i;j<n;j++){
                if(dic.find(s.substr(i, j-i+1))!= dic.end())
                    dp[i] = min(dp[i], dp[j+1]);
            }
        }
        return dp[0];
    }
};
