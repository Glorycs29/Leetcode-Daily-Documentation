//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    
int BS(long long n, vector<long long> &v, long long target, long long low, long long high, long long lb){
    
    if(low > high){
        return lb;
    }
    int mid = low + (high-low)/2;
    
    if(v[mid] <= target){
        lb = mid;
        return BS(n, v, target, mid+1, high, lb);
        //return mid;

    }else{
        return BS(n, v, target, low, mid-1, lb);
    }
    return -1;
}
    
    
    int findFloor(vector<long long> v, long long n, long long target){
        
        // floor in sorted array simply means lower bound function
        
        BS(n, v, target, 0, n-1, -1);
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends