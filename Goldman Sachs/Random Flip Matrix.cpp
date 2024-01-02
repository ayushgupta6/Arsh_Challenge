//link:https://leetcode.com/problems/random-flip-matrix/
class Solution {
public:
    set<pair<int,int>> st;
    int a,b;
    Solution(int m, int n) {
        a=m;
        b=n;
    }
    
    vector<int> flip() {
        int i=rand()%a;
        int j=rand()%b;
        if(st.find({i,j})==st.end()){
            st.insert({i,j});
            return {i,j};
        }
        return flip();
    }
    
    void reset() {
        st.clear();
    }
};
