//link: https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/
class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& ori, vector<char>& ch, vector<int>& cost) {
        vector<vector<int>> v(26, vector<int>(26, 1e9));
        for(int i=0;i<ori.size();i++)
            v[ori[i]-'a'][ch[i]-'a'] = min(cost[i],v[ori[i]-'a'][ch[i]-'a']);

        for(int i=0;i<26;i++)
            v[i][i]=0;

        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    if(i!=j){
                        v[j][k]= min(v[j][k], v[j][i]+v[i][k]);
                    }
                }
            }
        }  

        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a'][t[i]-'a']==1e9)
                return -1;
            ans += v[s[i]-'a'][t[i]-'a'];
        }      
        return ans;
    }
};
