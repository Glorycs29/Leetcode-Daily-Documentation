class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        if(m>n)return false;
        if(m==0)return true;
        int j=0;
        for(int i=0;i<n && j<m;i++){
            if(s[j]==t[i]){
                j++;
            }
        }
        return (j==s.length());
    }
};