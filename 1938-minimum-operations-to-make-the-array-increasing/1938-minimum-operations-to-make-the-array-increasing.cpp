class Solution {
public:
    int minOperations(vector<int>& nums) {

    if(nums.size()==1)
        return 0;
    int n=nums.size();
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] <= nums[i - 1])
        {
            count += abs(nums[i - 1] + 1 - nums[i]);
            nums[i] = nums[i - 1] + 1;
        }
    }
    return count;

    }
};