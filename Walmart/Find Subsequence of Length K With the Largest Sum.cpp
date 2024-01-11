//link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >  pq2;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<nums.size();i++)
            pq.push({nums[i], i});   

        vector<int> ans;
        while(k--){
            pq2.push({pq.top().second, pq.top().first});
            pq.pop();
        }
        while(!pq2.empty()){
            ans.push_back(pq2.top().second);
            pq2.pop();
        }
        return ans;
    }
};
