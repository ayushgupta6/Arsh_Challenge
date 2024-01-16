//link: https://leetcode.com/problems/matrix-cells-in-distance-order/description/
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int r, int c) {
        vector<vector<int>> ans;
        map<int,vector<vector<int>>> mp;

        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                mp[abs(r-i)+abs(c-j)].push_back({i,j});

        for(auto i:mp)
            for(auto j:i.second)
                ans.push_back(j);
        
        return ans;
    }
};
