class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //fibbonacci kind of problem
        int n=cost.size();
        vector<int> dp(3);
        for(int i=2;i<=n;i++){
            int jumpOneStep = dp[(i-1)%3] + cost[i-1];
            int jumpTwoStep = dp[(i-2)%3] + cost[i-2];
            dp[i%3] = min(jumpOneStep, jumpTwoStep);
        }
        return dp[n%3];
    }
};