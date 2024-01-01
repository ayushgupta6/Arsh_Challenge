//link: https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/
class Solution {
public:
    int mod=1e9+7;
    int memo(int curr, int k, int &end, vector<vector<int>> &dp){
        if(k==0)
            return curr==end;
        
        if(dp[curr][k]!=-1)
            return dp[curr][k];
        
        int ans = memo(curr-1,k-1,end, dp);
        ans = (ans+memo(curr+1,k-1,end, dp))%mod;
        return dp[curr][k]= ans;
        
    }
    int numberOfWays(int startPos, int endPos, int k) {
        endPos+=1000;
        vector<vector<int>> dp(3001, vector<int>(k+1, -1));
        return memo(1000+startPos,k, endPos, dp);
    }
};
