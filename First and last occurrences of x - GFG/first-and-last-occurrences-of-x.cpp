//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    //we can simply use liner traversal for finding 1st and last seperately
    // can use binary search for both 
    //can use lower_bound and upper_bound function
    
    int first = lower_bound(arr, arr+n,x)-arr;
    int last = upper_bound(arr, arr+n ,x)-arr;
    
    if(first == last){
        return {-1,-1};
    }
    else{
        return {first,last-1};
    }
    
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends