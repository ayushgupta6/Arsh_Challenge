//link: https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/
class Solution {
public:
    int solve(vector<int> &nums, int &n){
        int maxi=2;
        sort(nums.begin(), nums.end());
        int c=2;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]+1)
                c++;
            else{
                maxi = max(maxi,c);
                c=2;
            }
        }
        maxi = max(maxi,c);
        return maxi;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
     int t = min(solve(hBars,n), solve(vBars, m));
     return t*t;    
    }
};
