//link: https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1
string printMinNumberForPattern(string S){
    // code here 
    stack<char> st;
    int i;
    string ans;
    for(i=0;i<S.size();i++){
        if(S[i]=='I'){
            ans += ('1'+i);
            while(!st.empty()){
                ans += st.top();
                st.pop();
            }
        }
        else
            st.push('1'+i);
    }
    ans += ('1'+i);
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}
