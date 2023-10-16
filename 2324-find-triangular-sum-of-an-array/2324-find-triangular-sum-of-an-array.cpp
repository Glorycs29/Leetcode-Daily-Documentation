class Solution {
public:
    int triangularSum(vector<int>& arr) {
        while (arr.size() > 1) {
            int n = arr.size();
            vector<int> newNums(n - 1);
            for (int i = 0; i < n - 1; i++) {
                newNums[i] = (arr[i] + arr[i + 1]) % 10;
            }
            arr = newNums;  // Update arr with the newNums for the next iteration
        }
        return arr[0];
    }
};
