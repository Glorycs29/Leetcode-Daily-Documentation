class Solution {
public:

    // dp : size 20,10001 (diff can be negative but the index can't)
    int dp[20][10001];
    int solve(int idx, int diff, vector<int> &rods){
        
        if(idx == rods.size()){
            if(diff==0)return 0;
            return -1e5;
        }

        if(dp[idx][diff + 5000] != -1){
            return dp[idx][diff + 5000];
        }

        int ans1 = solve(idx+1, diff, rods);
        int ans2 =  rods[idx] + solve(idx+1, diff + rods[idx], rods);
        int ans3 = rods[idx] +  solve(idx+1, diff - rods[idx], rods);

        return dp[idx][diff + 5000] = max({ans1, ans2, ans3});
    }



    int tallestBillboard(vector<int>& rods) {
        memset(dp, -1, sizeof(dp));
        int ans  = solve(0, 0, rods)/2;        
        return ans;
    }
};
