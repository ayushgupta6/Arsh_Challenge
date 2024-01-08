//link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(auto i:edges)
            dist[i[0]][i[1]] = dist[i[1]][i[0]] = i[2];  

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
                }
            }
        } 

        int mini=1e9;
        int ans=-1;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=dt && i!=j)
                    c++;
            }
            if(c<=mini){
                mini=c;
                ans=i;
            }
        }
        return ans;
    }
};
