class Solution {
public:
    int countGoodSubstrings(string s) {
        int count=0, n = s.size();
        for(int i=0; i<=n-3; i++){
            if(s[i]!=s[i+1] && s[i]!=s[i+2] && s[i+1] != s[i+2]){
                count++;
            }
        }
        return count;
    }
};