//link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        for(auto i:edges){
            mat[i[0]][i[1]]=i[2];
            mat[i[1]][i[0]]=i[2];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    mat[j][k] = min(mat[j][k], mat[j][i]+mat[i][k]);
                }
            }
        }

        int ans=-1, c=1e9;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold && i!=j)
                    cnt++;
            }
            if(cnt<=c){
                c=cnt;
                ans=i;
            }
        }
        return ans;
    }
};
