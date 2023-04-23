class Solution {
public:
    int dfs(const string& s, long k, int i, vector<int>& dp) {
        if (i == s.size()) return 1;    // base case
        if (s[i] == '0') return 0;      // base case (no element should start with'0)
        if (dp[i] != -1) return dp[i]; // memoization

        int ans = 0;
        long num = 0;
        for (int j = i; j < s.size(); j++) {
            num = num * 10 + s[j] - '0';
            if (num > k) break;
            ans = (ans + dfs(s, k, j + 1, dp))%1000000007;
        }
        return dp[i] = ans; // store the ans i table
    }

    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(), -1);
        return dfs(s, k, 0, dp);
    }
};
