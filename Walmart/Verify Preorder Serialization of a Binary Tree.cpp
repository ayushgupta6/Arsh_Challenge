//link: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
class Solution {
public:
    bool isValidSerialization(string po) {
        if(po=="#")
            return true;
        if(po[0]=='#')
            return false;
        stack<int> st;
        st.push(2);
        int i=0;
        while(po[i]!=',')
            i++;
        po += ',';
        for(i++;i<po.size();i++){
            if(po[i]==','){
                if(po[i-1]=='#'){
                    if(st.empty())
                        return false;
                    int t= st.top();
                    st.pop();
                    if(t==2)
                        st.push(--t);
                }
                else{
                    if(st.empty())
                        return false;
                    if(!st.empty()){
                        int t= st.top();
                        st.pop();
                        if(t==2)
                            st.push(--t);    
                    }
                    st.push(2);
                }
            }    
        }
        return st.empty();
    }
};
