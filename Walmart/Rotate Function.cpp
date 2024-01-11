//link: https://leetcode.com/problems/rotate-function/description/
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int curr = 0, sum =0;
        int ans=INT_MIN, n=nums.size();

        for(int i=0;i<n;i++){
            curr += i*nums[i];
            sum += nums[i];
        }    
        ans = max(ans, curr);

        for(int i=1;i<n;i++){
            curr = curr+sum-(n*nums[n-i]);
            ans = max(ans, curr);
        }
        return ans;
    }
};
