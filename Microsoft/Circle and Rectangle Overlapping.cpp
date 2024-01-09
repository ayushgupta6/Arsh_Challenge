//link: https://leetcode.com/problems/circle-and-rectangle-overlapping/description/
class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2, int y2) {
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                long long pr=(i-xc)*(i-xc) + (j-yc)*(j-yc);
                long long r=radius*radius;
                if(pr<=r) return true;
            }
        }
        return false;
    }
};
