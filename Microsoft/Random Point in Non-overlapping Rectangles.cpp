//link: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/
class Solution {
public:
    vector<vector<int>> v;
    vector<int> areasum;
    int totalareasum=0;
    Solution(vector<vector<int>>& rect) {
        for(auto i:rect){         
            int area=(i[3]-i[1]+1)*(i[2]-i[0]+1);
            totalareasum+=area; 
            v.push_back(i);
            areasum.push_back(totalareasum);
        }
    }
    
    vector<int> pick() {
        int c = rand()%totalareasum;
        int i = upper_bound(areasum.begin(), areasum.end(),c)-areasum.begin();
        int x = rand()%(v[i][2]-v[i][0]+1)+v[i][0];
        int y = rand()%(v[i][3]-v[i][1]+1)+v[i][1];
        return {x,y};
    }
};
