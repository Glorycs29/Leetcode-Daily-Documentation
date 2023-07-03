class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.size())return false;
        // now traversing the whole string and count the unmatched elements
        // if that count is eqauls to 2 then true otherwise false
        int count=0, trav=0;
        vector<int> v(26,0), g(26,0);
        set<char> ss,gs;
        for(int i=0; i<s.size(); i++){
            if(s[i] != goal[i]) trav++;
            v[s[i]-'a']++;
            ss.insert(s[i]);
            gs.insert(goal[i]);
            g[goal[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(v[i] != g[i])
            count += abs(v[i]-g[i]);
        }
        if(count!=0)return false;
        if(s==goal){
            if(ss.size()<s.size())return true;
            return false;
        }
        else if(trav==2 || trav==0) return true;
        else return false;
    }
};
