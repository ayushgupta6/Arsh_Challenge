//link: https://leetcode.com/problems/bulls-and-cows/description/
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> c(10, 0), c2(10,0);
        int bull=0, cow=0;
        for(auto i:secret)
            c[i-'0']++;
        
        for(int i=0;i<guess.size();i++){
            if(secret[i]==guess[i]){
                bull++;
                c[secret[i]-'0']--;
            }
            else
                c2[guess[i]-'0']++;
        }
        for(int i=0;i<10;i++)
            cow += min(c[i],c2[i]);
        
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
};
