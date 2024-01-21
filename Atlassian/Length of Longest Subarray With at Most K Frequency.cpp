//link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        int ans=0, i=0, j=0;

        while(i<nums.size()){
            mp[nums[i]]++;

            if(mp[nums[i]]>k){
                while(j<=i && nums[j]!=nums[i]){
                    mp[nums[j++]]--;
                }
                mp[nums[j]]--;
                j++;
            }
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;

    }
};
