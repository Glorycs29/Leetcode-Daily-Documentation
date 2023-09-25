class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int count=0;
        long power = pow(10,k);
        
        for(int n=num; n>0; n/=10){
            int divisor = n % power;
            if(divisor != 0 && num % divisor == 0) count++;

            if(n/power == 0) break;
        }
        return count;
    }
};