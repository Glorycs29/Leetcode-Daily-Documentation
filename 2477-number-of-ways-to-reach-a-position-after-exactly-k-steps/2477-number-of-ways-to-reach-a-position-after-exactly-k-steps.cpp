class Solution {
private:
    int count(int start, int end, int k, vector<vector<int>> &dp) {
        
        if(k == 0) {
            if(start == end) {
                return 1;
            }
            else {
                return 0;
            }
        }
        if(k < 0) {
            return 0;
        }
        
        if(dp[start + 1000][k] != -1) return dp[start + 1000][k];
        
        int front = count(start + 1, end, k - 1, dp) % mod;
        int back = count(start - 1, end, k - 1, dp) % mod;
        
        return dp[start + 1000][k] = (front + back) % mod;
    }
public:
    int mod = (int) 1e9 + 7;
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3001, vector<int>(k + 1, -1));
        return count(startPos, endPos, k, dp);
    }
};