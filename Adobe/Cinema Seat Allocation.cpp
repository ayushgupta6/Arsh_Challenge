//link: https://leetcode.com/problems/cinema-seat-allocation/description/
class Solution {
public:
    int count(int ind){
        bool l,c,r;
        l=c=r=1;

        for(auto i:mp[ind]){
            if(i>=2 && i<=5)    l=0;
            if(i>=4 && i<=7)    c=0;
            if(i>=6 && i<=9)    r=0;
        }

        if(l && c && r)
            return 2;
        else if(l || c || r)
            return 1;
        return 0;    
    }
    unordered_map<int, vector<int>> mp;
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        for(auto i: reservedSeats)
            mp[i[0]].push_back(i[1]);

        int ans=0;
        for(auto i:mp){
            ans += count(i.first);
        }  
        ans += (n-mp.size())*2;
        return ans;
    }
};
