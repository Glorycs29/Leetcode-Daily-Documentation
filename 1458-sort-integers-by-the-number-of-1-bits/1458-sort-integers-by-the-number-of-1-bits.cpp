class Solution {
public:
    static int bit(int n){
        int cnt =0;
        while(n){
            cnt+=n&1;
            n=n>>1;
        }
        return cnt;
    }

    static bool comp(int a, int b){
        int x = bit(a);
        int y = bit(b);
        if(x==y) return a<=b;
        return x<=y;    
    }


    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};