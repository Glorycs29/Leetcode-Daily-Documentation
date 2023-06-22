class Solution{
bool lemonadeChange(int N, vector<int> &bills) {
        // code here


        int a=0;   //  5$
        int b=0;   //  10$


        for(int i=0;i<N;i++){
            if(bills[i]==5) a++;

            else if(bills[i]==10 && a!=0) {
                a--;
                b++;
            }
            else if(bills[i]==20 && (a!=0 && b!=0)){
                a--;
                b--;
            }
            else if(bills[i]==20 && a>2){
                a=a-3;
            }
            else return false;
        }
        return true;
    }
};
