class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch;
        int x=0;
        for(int i=0;i<s.size();i++) x^=(int)s[i];
        for(int i=0;i<t.size();i++) x^=(int)t[i];
        return char(x);
    }
};