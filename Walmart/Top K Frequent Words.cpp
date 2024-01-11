//link: https://leetcode.com/problems/top-k-frequent-words/description/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto i:words)
            mp[i]++;

        vector<pair<int,string>> v;
        for(auto i:mp)
            v.push_back({i.second, i.first});  

        auto lambda = [](pair<int, string>& p1, pair<int, string>& p2) {
            if(p1.first == p2.first)
                return p1.second < p2.second;
            
            return p1.first > p2.first;
        };
        sort(v.begin(), v.end(), lambda);
        vector<string> ans;
        int i=0;
        while(k--){
            ans.push_back(v[i++].second);
        }

        return ans;
    }
};
