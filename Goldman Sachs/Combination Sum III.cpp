//link:- https://leetcode.com/problems/combination-sum-iii/
class Solution {
public:
    void make(vector<int> &v){
        vector<int> tans;
        for(int i=1;i<=9;i++)
            if(v[i]==1)
                tans.push_back(i);

        if(find(ans.begin(), ans.end(), tans)==ans.end())
            ans.push_back(tans);
    }
    vector<vector<int>> ans;
    void possible(int n, int k, vector<int> &v){
        if(k==0){
            if(n==0)
                make(v);
            return;
        }
        if(n<0)
            return;

        for(int i=1;i<=9;i++){
            if(v[i]==0){
                v[i]=1;
                possible(n-i, k-1, v);
                v[i]=0;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v(10, 0);
        possible(n, k, v);
        return ans;
    }
};
