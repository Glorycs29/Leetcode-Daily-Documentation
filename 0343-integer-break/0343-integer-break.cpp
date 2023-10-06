class Solution {
public:
    // let's use top-down approach(memoization)
    vector<int> dp;

    int integerBreak(int n) {
        if(n<=3)
            return n-1;
        dp = vector(n+1,0);
        return intBreak(n);
    }
    
    int intBreak(int num){
        if(num<=3){
            return num;
        }

        if(dp[num]!=0){
            return dp[num];
        }

        int ans = num;
        for(int i=2; i<num; i++){
            ans = max(ans, i*intBreak(num-i));
        }
        dp[num] = ans;
        return ans;
    }
};