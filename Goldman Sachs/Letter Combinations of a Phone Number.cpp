//link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
private:
    void rec(int i, int &n, string &d, string &tans, vector<string> &ans){
        if(i==n){
            ans.push_back(tans);
            return;
        }
        
        int j = d[i]-'0';
        string s = maps[j];
        for(int k=0;k<s.size();k++){
            tans += s[k];
            rec(i+1, n, d, tans, ans);
            tans.pop_back();
        }
    }
public:
    vector<string> maps={"", "", "abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string d) {
        string tans;
        vector<string> ans;
        int n = d.size();
        if(n==0)
            return ans;

        rec(0, n, d, tans, ans);
        return ans;
    }
};
