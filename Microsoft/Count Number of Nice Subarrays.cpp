//link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd=0, ans=0, c=0;
        int i=0,j=0;

        while(j<nums.size()){
            if(nums[j]%2==1){
                odd++;
                if (odd >= k) {
                    c = 1;
                    while(nums[i++]%2==0) c++;
                    ans += c;
                }
            }
            else if(odd>=k) 
                ans += c;
            j++;
        }   
        return ans;
    }
};
