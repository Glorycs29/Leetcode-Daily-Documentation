

class Solution{
int sumOfNaturals(int n) {
        // code here
        int mod=1e9+7;
        long ans=(long)n*(long)(n+1);
        ans/=2;
        return ans%mod;
    }
};
