class Solution {
public:
    int integerBreak(int n) {
        if(n==2 || n==3) return (n-1);
        // if n is still greater than 4 then, take out the size of 3 out
        int res=1;
        while(n>4){
            n-=3;
            res*=3;
        }
        return (n*res);
    }
};