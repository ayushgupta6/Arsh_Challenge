//link: https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/description/
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> st;
        int ans=0;
        for(auto &i:startWords){
            sort(i.begin(), i.end());
            st.insert(i);
        }

        for(auto &i:targetWords){
            sort(i.begin(),i.end());
            for(int j=0;j<i.size();j++){
                string t=i;
                t.erase(j, 1);
                if(st.find(t)!=st.end()){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
