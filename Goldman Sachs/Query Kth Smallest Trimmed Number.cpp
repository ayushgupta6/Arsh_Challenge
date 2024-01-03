//link: https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int s=nums[0].size();
        unordered_map<int, vector<pair<string,int>>> mp;
        vector<int> ans;

        for(auto q:queries){
            if(mp.find(q[0])!=mp.end()){
                ans.push_back(mp[q[1]][q[0]-1].second);
            }
            else{
                vector<pair<string,int>> v;
                for(int i=0;i<nums.size();i++){
                    v.push_back({nums[i].substr(s-q[1],q[1]),i});
                }
                sort(v.begin(), v.end());
                ans.push_back(v[q[0]-1].second);
            }
        }    
        return ans;
    }
};
