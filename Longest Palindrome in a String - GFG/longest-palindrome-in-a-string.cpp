//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        string str="";
        int n=s.length();
        
        //iterate over the string
        for(int i=0;i<n;i++){
            
            //initialize two pointer
            int left=i, right=i;
            
            
            // expand the range of palindrome,
            // while two pointers are same 
            
            while(left>=0 && s[left]==s[i])left--;
            while(right<n && s[right]==s[i])right++;
            
            // expand the range of palindrome,
            // while two pointers are same 
            
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
            }
            
            // get the substring that is palindrome
            string candidate = s.substr(left+1, right-left-1);
            // now check,
            // if current palindrome is longer than the previous one
            if(candidate.length()>str.length()){
                str=candidate;
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends