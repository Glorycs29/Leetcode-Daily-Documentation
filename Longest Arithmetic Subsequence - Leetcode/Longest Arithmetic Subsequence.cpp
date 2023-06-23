class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2000, 0));
        // dp[index][diff] equals to the length of arithmetic sequence at index with difference diff.
        int res =2; 
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++){
                int diff = nums[j]-nums[i] + 1000;
                dp[j][diff] = max(2, dp[i][diff]+1);
                res = max(res, dp[j][diff]);
            }
        return res;        
    }
};
