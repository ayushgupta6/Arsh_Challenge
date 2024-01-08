//link: https://leetcode.com/problems/wiggle-sort-ii/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int> v=nums;
        sort(v.begin(), v.end());
        int i=1, j=n-1;

        while(i<n){
            nums[i] = v[j--];
            i+=2;
        }
        i=0;
        while(i<n){
            nums[i] = v[j--];
            i+=2;
        }
    }
};
