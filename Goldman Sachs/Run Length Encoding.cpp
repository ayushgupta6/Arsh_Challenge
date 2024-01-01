//link: https://practice.geeksforgeeks.org/problems/run-length-encoding/1
string encode(string src)
{     
  //Your code here 
    char prev=src[0];
    int c=1;
    string ans="";
    for(int i=1;i<src.size();i++){
        if(src[i]==prev)
            c++;
        else{
            ans+=prev;
            ans += to_string(c);
            prev=src[i];
            c=1;
        }
    }
    ans+=prev;
    ans += to_string(c);
    return ans;
}  
