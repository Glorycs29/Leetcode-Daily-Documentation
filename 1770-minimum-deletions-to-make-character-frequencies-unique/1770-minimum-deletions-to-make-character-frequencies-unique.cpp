class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mp;
        set<int> st;
        int deletion =0;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        for(auto x: mp){
            while(st.find(x.second)!=st.end()){
                x.second--;
                deletion++;
            }
            if(x.second > 0){
                st.insert(x.second);
            }
        }
        return deletion;
    }
};