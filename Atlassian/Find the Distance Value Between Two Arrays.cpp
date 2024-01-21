//link: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/description/
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        //brute force
        /*
        int ans=0;
        for(int i=0;i<arr1.size();i++){
            for(int j=0;j<arr2.size();j++){
                if(abs(arr1[i]-arr2[j])<=d){
                    ans++;
                    break;
                }
            }
        }
        return arr1.size()-ans;
        */
        //optimize
        sort(arr2.begin(), arr2.end());
        int ans=0;

        for(int i=0;i<arr1.size();i++){
            int s=0, e=arr2.size()-1;
            while(s<=e){
                int mid= (s+e)/2;

                if(abs(arr1[i]-arr2[mid])<=d){
                    ans++;
                    break;
                }
                else if(arr1[i]<arr2[mid]){
                    e=mid-1;
                }
                else
                    s=mid+1;
            }
        }
        return arr1.size()-ans;
    }
};
