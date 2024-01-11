//link: https://leetcode.com/problems/friends-of-appropriate-ages/description/
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> agecount(121, 0);

        for(auto i:ages)
            agecount[i]++;

        int ans=0;
        for(int x=7;x<121;x++){
            for(int y=((x/2)+8);y<=x;y++){
                if(y==x)
                    ans -= agecount[x];
                ans += agecount[x]*agecount[y];
            }
        }
        return ans;
    }
};
