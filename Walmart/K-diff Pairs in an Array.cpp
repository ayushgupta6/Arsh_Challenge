//link: https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> mp;
        set<pair<int,int>> st;

        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-k)!=mp.end()){
                int a=nums[i], b=nums[i]-k;
                if(a>b)
                    swap(a,b);
                if(st.find({a,b})==st.end())
                    st.insert({a,b});
            }
            if(mp.find(nums[i]+k)!=mp.end()){
                int a=nums[i], b=nums[i]+k;
                if(a>b)
                    swap(a,b);
                if(st.find({a,b})==st.end())
                    st.insert({a,b});
            }
            mp.insert(nums[i]);
        }
        return st.size();
    }
};
