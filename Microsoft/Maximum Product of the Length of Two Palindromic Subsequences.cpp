//link:https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/
class Solution {
public:
    int palin(string &s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i++]!=s[j--])
                return 0;
        }
        return s.size();
    }
    int memo(int ind, string &s, string&s1, string &s2){
        if(ind<0)
            return palin(s1)*palin(s2);
        
        int ans=0;
        s1+=s[ind];
        ans = max(ans, memo(ind-1, s, s1, s2));
        s1.pop_back();

        s2+=s[ind];
        ans = max(ans, memo(ind-1, s, s1, s2));
        s2.pop_back();

        return max(ans, memo(ind-1, s, s1, s2));
    }
    int maxProduct(string s) {
        string s1, s2;
        return memo(s.size()-1, s, s1, s2);    
    }
};
