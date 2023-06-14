//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int n, vector<int>& arr, int target) {
        int low = 0, high = n-1;
        
        if(low>high)return false;
        while(low <= high){
        int mid = (high+low)/2;
        // ideal case
        if(arr[mid] == target){
            //cout<<"idx : "<<mid;
            return true;
        }
        
        // special case :
        // arr[] = {3, 1, 2, 3, 3, 3, 3}
        
        if(arr[mid] == arr[low] && arr[mid] == arr[high]){
            low++;
            high--;
        }
        
        // trimming right if left is sorted
        if(arr[mid] >= arr[low]){
            if(arr[low] <= target && arr[mid] >= target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        // trimming left if right is sorted
        else{
            if(arr[mid] <= target && arr[high] >= target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }
    return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends