//link: https://leetcode.com/problems/find-players-with-zero-or-one-losses/description
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        unordered_map<int,int> loss;
        unordered_set<int> win;

        for(int i=0;i<m.size();i++){
            loss[m[i][1]]++;
            if(win.find(m[i][1])!=win.end())
                win.erase(m[i][1]);
            if(loss.find(m[i][0])==loss.end())
                win.insert(m[i][0]);
            else
                win.erase(m[i][0]);
        }

        vector<vector<int>> ans(2);
        for(auto i:loss)
            if(i.second == 1)
                ans[1].push_back(i.first);
    
        for(auto i:win)
            ans[0].push_back(i);
        
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};
