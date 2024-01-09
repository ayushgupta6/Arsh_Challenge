//link: https://leetcode.com/problems/shopping-offers/description/
class Solution {
public:
    map<vector<int> ,int> mp;
    int memo(vector<int> &remain, vector<int>& price, vector<vector<int>>& offer){
        if(mp.find(remain)!=mp.end())
            return mp[remain];

        int ans=0;
        int n=remain.size();
        for(int i=0;i<n;i++)
            ans += remain[i]*price[i];

        for(auto o:offer){
            vector<int> c=remain;
            int j=0;
            for(j;j<n;j++){
                int d=c[j]-o[j];
                if(d<0) break;
                c[j] -= o[j];
            }
            if(j==n)
                ans = min(ans, o[j]+memo(c,price, offer));
        }        
        return mp[remain] = ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return memo(needs, price, special);
    }
};
