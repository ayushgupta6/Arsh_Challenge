//link: https://leetcode.com/problems/get-equal-substrings-within-budget/description/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0,j=0;
        int ans=0, cost=0;

        while(j<s.size()){
            cost += abs(s[j]-t[j]);
            while(i<=j && cost>maxCost){
                cost -= abs(s[i]-t[i]);
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }    
        return ans;
    }
};
