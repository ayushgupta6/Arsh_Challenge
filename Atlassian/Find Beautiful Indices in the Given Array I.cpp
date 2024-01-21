//link: https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/description/
class Solution {
public:
    vector<int> solve(string &s, string &t){
        int n=s.size(), m=t.size();
        vector<int> ans;

        for(int i=0;i<=n-m;i++){
            if(s.substr(i,m)==t)
                ans.push_back(i);
        }

        return ans;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ind_a, ind_b, ans;

        ind_a = solve(s,a);
        ind_b = solve(s,b);

        for(int i=0;i<ind_a.size();i++){
            for(int j=0;j<ind_b.size();j++)
                if(abs(ind_b[j]-ind_a[i])<=k){
                    ans.push_back(ind_a[i]);
                    break;
                }
        }
        return ans;
    }
};
