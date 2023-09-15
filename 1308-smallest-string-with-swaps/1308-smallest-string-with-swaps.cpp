static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class UnionFind{
    private:
        vector<int> _p, _s;
    public:
        UnionFind(int n): _p(n), _s(n){
            for(int i = 0; i < n; i++){
                _p[i] = i;
                _s[i] = 1;
            }
        }

        int Find(int x){
            if(x==_p[x]){
                return x;
            }
            return _p[x] = Find(_p[x]);
        }

        bool Union(int x, int y){
            int px = Find(x);
            int py = Find(y);
            if(px == py)
                return false;
            if(_s[px]>_s[py]){
                _p[py] = px;
                _s[px]+=_s[py]; 
            }
            else{
                _p[px] = py;
                _s[py]+=_s[px];
            }
            return true;
        }
        void print(){
            cout << "_p: ";
            for(auto& p : _p){
                cout << p << " ";
            }
            cout << endl;

            cout << "_s: ";
            for(auto& s : _s){
                cout << s << " ";
            }
            cout << endl;
        
        }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        UnionFind ufs(s.size());
        //ufs.print();
        for(auto& p : pairs){
            ufs.Union(p[0], p[1]);
            //ufs.print();
        }
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < s.size(); i++){
            mp[ufs.Find(i)].push_back(i);
        }
        for(auto& [k, v] : mp){
            string ss;
            for(auto& i : v){
                ss.push_back(s[i]);
            }
            sort(ss.begin(), ss.end());
            for(int i = 0; i < v.size(); i++){
                s[v[i]] = ss[i];
            }
        }
        return s; 
    }
};