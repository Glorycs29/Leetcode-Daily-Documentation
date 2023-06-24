class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        string comp = str.substr(0,k);
        int res=0;
        for(int i=0; i<n; i++){
            if(arr[i].size() >= k && arr[i].substr(0,k)==comp)
                res++;
        }
        return res;
    }
};
