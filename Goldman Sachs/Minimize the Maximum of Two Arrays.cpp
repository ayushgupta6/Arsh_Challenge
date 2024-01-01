//link:- https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/
class Solution 
{
   #define ll long long 
   public:
    int minimizeSet(int d1, int d2, int cnt1, int cnt2) 
    {
        ll lcm = ((ll)d1 / gcd(d1, d2)) * d2;
        ll low=0,high=1e18;
        ll ans=0;
        while(low<=high)
        {
            ll mid=(low+high)/2;
            ll a=mid-mid/(ll)d1;
            ll b=mid-mid/(ll)d2;
            ll c=mid-mid/d1-mid/d2+mid/(lcm);
            if(a>=cnt1 and b>=cnt2 and (a+b-c)>=(cnt1+cnt2)){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;    
    }
};
