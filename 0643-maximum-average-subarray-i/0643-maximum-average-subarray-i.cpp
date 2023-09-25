class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_avg=INT_MIN, sum=0;
        int n=nums.size();
        for(int i=0; i<k; i++){
            sum+=nums[i];
        }
        max_avg=sum;
        for(int i=0; i<n-k; i++){
            sum+=nums[i+k]-nums[i];
            max_avg = max(max_avg, sum);
        }
        return max_avg/k;
    }
};