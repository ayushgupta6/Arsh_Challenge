//link: https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/description/
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans=0, n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                bool t=true;
                int prev=-1;
                for(int x=0;x<n;x++){
                    if(x>=i && x<=j)
                        continue;
                    if(nums[x]<=prev){
                        t=0;
                        break;
                    }
                    prev=nums[x];
                }
                if(t)  ans++;
            }
        }
        return ans;
    }
};
