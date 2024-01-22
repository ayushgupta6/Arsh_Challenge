//link: https://leetcode.com/problems/count-collisions-on-a-road/description/
class Solution {
public:
    int countCollisions(string d) {
        int ans=0;
        stack<char> st;

        for(int i=0;i<d.size();i++){
            if(d[i]=='R')
                st.push('R');

            else if(d[i]=='L'){
                if(!st.empty() && st.top()=='S')
                    ans++;
                else if(!st.empty() && st.top()=='R'){
                    ans+=2;
                    st.pop();
                    while(!st.empty() && st.top()=='R'){
                        ans++;
                        st.pop();
                    }
                    st.push('S');
                }
            }
            else{
                if(!st.empty() && st.top()=='R'){
                    while(!st.empty() && st.top()=='R'){
                        ans++;
                        st.pop();
                    }
                }
                st.push('S');
            }
        }
        return ans;
    }
};
