class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int sum = 0;
        for (int i = 0; i < k; ++i) sum += nums[i];

        int max_sum = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k];
            max_sum = max(sum, max_sum);
        }

        return static_cast<double>(max_sum) / k;
    }
};