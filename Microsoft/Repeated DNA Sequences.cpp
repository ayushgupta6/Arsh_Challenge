//link: https://leetcode.com/problems/repeated-dna-sequences/description/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int st=s.size();
        if(st<=10)
            return ans;
        unordered_map<string, int> mp;
        string ss="";
        for(int i=0;i<10;i++)
            ss+=s[i];
        mp[ss]++;
        for(int i=10;i<st;i++){
            ss.erase(0,1);
            ss+=s[i];
            mp[ss]++;
        }

        for(auto i:mp){
            if(i.second>1)
                ans.push_back(i.first);
        }
        return ans;
    }
};
