class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        
        int i, len=0, sum1=0, target=-x;
        for(i=0; i<v.size(); i++)
            target+=v[i];

        if(target==0)
            return v.size();
        int j; i=0;
        for(j=0; j<v.size(); j++){
            sum1+=v[j];

            while(i<v.size() && sum1>target)
                sum1-=v[i++];

            if(sum1==target)
                len=max(len,j-i+1);
        }
        if(!len)
            return -1;
        return v.size()-len;
    }
};