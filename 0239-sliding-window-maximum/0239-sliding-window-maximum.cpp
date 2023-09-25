class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n = nums.size();
    vector <int> res;
    
    if(n == 0)
        return res;
    if(k == 1)
        return nums;
    
    int left[n]; 
    int right[n]; 
    
    left[0] = nums[0];
    right[n - 1] = nums[n - 1];
    
    //max from left in the windows of k
    for(int i = 0;i < n;i++)
    {
        if(i % k == 0)
        left[i] = nums[i];
        else
        left[i] = std::max(nums[i],left[i - 1]);
    } 
    
    // max from right in the windows of k
    for(int i = n - 2;i >= 0;i--)
    {
        if(i % k == 0)
        right[i] = nums[i];
        else
        right[i] = std::max(nums[i],right[i + 1]);
    } 
    
    //overall maximum
    for(int i = 0; i <= n - k;i++)
    {
        res.push_back(std::max(right[i],left[i + k - 1]));
    }
    return res;
    }
};