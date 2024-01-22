//link: https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        unordered_map<int, vector<pair<string,int>>> mp;
        int s = nums[0].size();
        vector<int> ans;

        for(auto i:queries){
            if(mp.find(i[1])!=mp.end()){
                ans.push_back(mp[i[1]][i[0]-1].second);
            }
            else{
                vector<pair<string,int>> v;
                for(int j=0;j<nums.size();j++)
                    v.push_back({nums[j].substr(s-i[1],i[1]),j});
                
                sort(v.begin(), v.end());
                mp[i[1]] = v;
                ans.push_back(v[i[0]-1].second);
            }
        }
        return ans;
    }
};
