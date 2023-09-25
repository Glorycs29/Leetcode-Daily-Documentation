class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        ios_base::sync_with_stdio;
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n=arr.size(), sum=0, cnt=0;
        for(int i=0;i<k; i++) sum+=arr[i];
        if(sum/k >= threshold) cnt++;

        for(int i=0; i<n-k; i++){
            // sum*=k;
            sum+=arr[i+k]-arr[i];
            if(sum/k >= threshold) cnt++;
        }
        return cnt;
    }
};