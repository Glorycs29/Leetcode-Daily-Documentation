class Solution {
public:
    int triangularSum(vector<int>& arr) {
        while (arr.size() > 1) {
            int n = arr.size();
            for (int i = 0; i < n - 1; i++) {
                arr[i] = (arr[i] + arr[i + 1]) % 10;
            }
            arr.pop_back();  // Remove the last element after updating the array
        }
        return arr[0];
    }
};
