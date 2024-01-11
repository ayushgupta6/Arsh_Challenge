//link: https://leetcode.com/problems/largest-divisible-subset/description/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> dp(n, 1), parent(n);
        for(int i=0;i<n;i++)
            parent[i]=i;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]= dp[j]+1;
                    parent[i]=j;
                }
            }
        }
        int maxi = 0, ind=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i];
                ind=i;
            }
        }
        vector<int> ans;

        while(parent[ind]!=ind){
            ans.push_back(nums[ind]);
            ind=parent[ind];
        }
        ans.push_back(nums[ind]);
        return ans;
    }
};
