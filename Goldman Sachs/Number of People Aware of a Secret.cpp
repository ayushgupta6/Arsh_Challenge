//link: https://leetcode.com/problems/number-of-people-aware-of-a-secret/
class Solution {
public:   
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int ans=0, mod=1e9+7;
        vector<int> day(n+1,0);
        day[1]=1;

        for(int i=1;i<=n;i++){
            for(int j=i+delay; j<=min(n, i+forget-1);j++){
                day[j]= (day[j]+day[i])%mod;
            }
        }

        for(int i=n;i>n-forget;i--)
            ans = (ans+day[i])%mod;

        return ans;
    }
};
