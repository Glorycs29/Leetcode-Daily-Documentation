//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
    int low = 0, high=n-1;
    
    while(low < high){
            // if already sorted
        if(arr[low] < arr[high]) return arr[low];
        int mid= low + (high-low)/2;

        // sample example : {4, 5, 6, 7, 0, 1, 2}
        if(arr[low] <= arr[mid]){
            
            low = mid+1;
        }else{
            high = mid;
        }
    }
    return arr[low];
    
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends