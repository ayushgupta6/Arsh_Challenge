//link: https://leetcode.com/problems/map-of-highest-peak/
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& M) {
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        int n=M.size(), m=M[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(M[i][j]==1){
                    q.push({i,j});
                    M[i][j]=-1;
                }
        
        while(!q.empty()){
            int ci=q.front().first;
            int cj=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int ni=ci+dx[i], nj=cj+dy[i];
                if(ni>=0 && ni<n && nj>=0 && nj<m && M[ni][nj]!=-1){
                    ans[ni][nj] = ans[ci][cj]+1;
                    q.push({ni,nj});
                    M[ni][nj]=-1;
                }
            }
        }
        return ans;
    }
};
