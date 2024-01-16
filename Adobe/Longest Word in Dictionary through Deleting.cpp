//link: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/
class Solution {
public:
    bool ispresent(string &s, string &t){
        int i=s.size()-1,j=t.size()-1;
        while(i>=0 && j>=0){
            if(s[i]==t[j])
                j--;
            i--;
        }
        return j<0;
    }
    static bool comp(string &s1, string &s2) { 
        if(s1.size()==s2.size())
            return s1<s2;
        return s1.size()>s2.size(); 
    } 
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), comp);

        for(auto i:d)
            if(ispresent(s, i))
                return i;
        return "";

    }
};
