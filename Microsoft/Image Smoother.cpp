//link: https://leetcode.com/problems/image-smoother/
class Solution {
public:
    int n,m;
    int average(vector<vector<int>>& img, int i, int j){
        int c=0;
        int sum=0;
        for(int x=-1;x<2;x++){
            for(int y=-1;y<2;y++){
                int nx=x+i;
                int ny=y+j;
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    sum+= img[nx][ny];
                    c++;
                }
            }
        }
        return sum/c;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        n = img.size();
        m = img[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = average(img, i, j);
            }
        }
        return ans;
    }
};
