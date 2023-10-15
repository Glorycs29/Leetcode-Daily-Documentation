class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1000000007;
        std::vector<std::vector<long long>> memo(steps + 1, std::vector<long long>(std::min(arrLen, steps) + 1, -1));
        
        return dp(steps, 0, arrLen, MOD, memo);
    }
    
    long long dp(int step, int index, int arrLen, const int MOD, std::vector<std::vector<long long>>& memo) {
        if (step == 0) {
            return (index == 0) ? 1 : 0;
        }
        if (step < 0 || index < 0 || index >= arrLen) {
            return 0;
        }
        if (memo[step][index] != -1) {
            return memo[step][index];
        }
        
        long long ways = dp(step - 1, index, arrLen, MOD, memo) % MOD;
        ways += dp(step - 1, index - 1, arrLen, MOD, memo) % MOD;
        ways += dp(step - 1, index + 1, arrLen, MOD, memo) % MOD;
        
        memo[step][index] = ways % MOD;
        return ways % MOD;
    }
};