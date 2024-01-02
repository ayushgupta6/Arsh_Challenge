//link: https://leetcode.com/problems/high-access-employees/description/
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        unordered_map<string, vector<int>> mp;
        for(auto i:at)
            mp[i[0]].push_back(stoi(i[1]));

        vector<string> ans;
        for(auto i:mp){
            if(i.second.size()<3)
                continue;
            sort(i.second.begin(), i.second.end());
            for(int j=0;j<i.second.size()-2;j++){
                int maxi = i.second[j];
                maxi += i.second[j]%100==0?60:100;
                if(i.second[j+2]<maxi){
                    ans.push_back(i.first);
                    break;
                }
            }
        }
        return ans;
    }
};
