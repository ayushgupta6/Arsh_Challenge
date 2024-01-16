//link: https://leetcode.com/problems/construct-the-longest-new-string/description/
class Solution {
public:
    int longestString(int x, int y, int z) {
        return 2*(2*min(x,y)+z) + (x!=y?2:0);
    }
};
