//link: https://leetcode.com/problems/battleships-in-a-board/description/
class Solution {
public:
    int countBattleships(vector<vector<char>>& b) {
        int ans=0, n = b.size(), m = b[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]=='X'){
                    if(j<m-1 && b[i][j+1]=='X'){
                        int t=j;
                        while(t<m && b[i][t]=='X'){
                            b[i][t]='*';
                            t++;
                        }
                    }
                    else if(i<n-1 && b[i+1][j]=='X'){
                        int t=i;
                        while(t<n && b[t][j]=='X'){
                            b[t][j]='*';
                            t++;
                        }
                    }
                    ans++;
                    b[i][j] = '*';
                }
            }
        }
        return ans;
    }
};
