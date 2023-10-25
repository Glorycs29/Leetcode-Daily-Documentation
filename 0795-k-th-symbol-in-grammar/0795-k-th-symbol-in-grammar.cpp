class Solution {
public:
    
    int solve(int n,int k){
        if(n==1 && k==1)return 0;
        
        //finding mid :- 
        //as we can see length in each row inc by x2
        int mid = (pow(2,n-1))/2;
        
        //if k lies before mid 
        //say for nth row elements before mid
        //are equal to (n-1)th row.
        if(k <=mid)return solve(n-1,k);
        
        //else k lies after mid
        //which is equals to !(n-1)th row elements before mid.
        
        return !solve(n-1,k-mid);
    }
    int kthGrammar(int n, int k) {
        
        return solve(n,k);
    }
};
//0
//0 1
//0 1 1 0
//0 1 1 0 1 0 0 1
/*
here we can observe that length is getting twice in each row
and elements before mid of nth row is equal to (n-1)th row
and elements after mid of nth row is equals to !(n-1)th row elements.
*/