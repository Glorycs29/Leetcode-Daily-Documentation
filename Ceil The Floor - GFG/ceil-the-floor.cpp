//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int ans_floor=-1, ans_ceil =-1;
    
    for(int i=0;i<n;i++){
        if(arr[i]<=x && ans_floor<=arr[i]){
            ans_floor = arr[i];
        }
        if(arr[i]>=x && ans_ceil==-1) ans_ceil = arr[i];
        if(arr[i]>=x && ans_ceil>arr[i]){
            ans_ceil = arr[i];
        }
    }
    return make_pair(ans_floor, ans_ceil);
}