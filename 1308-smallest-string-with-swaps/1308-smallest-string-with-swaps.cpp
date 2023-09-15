class DSU{
private:

    int *parent;
    int *size;

public:

    DSU(int v){
        size = new int[v];
        parent = new int[v];
        for(int i = 0; i < v; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int Find(int node){
        if(parent[node] != node){
            return parent[node] = Find(parent[node]); // path compression step.
        }
        return node;
    }

    void Union(int u,int v){
        int up = Find(u);
        int vp = Find(v);
        if(up == vp) return;
        if(size[up] < size[vp]){
            parent[up] = vp;
            size[vp] += size[up];
        }
        else{
            parent[vp] = up;
            size[up] += size[vp];
        }
    }

};




class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DSU dsu(s.size());
        for(auto p : pairs){
            dsu.Union(p[0], p[1]);
        }
        map<int, multiset<char>> mp;
        for(int i=0; i<s.size(); i++){
            mp[dsu.Find(i)].insert(s[i]);
        }

        for(int i=0; i<s.size(); i++){
            auto it = mp[dsu.Find(i)].begin();
            s[i] = *it;
            mp[dsu.Find(i)].erase(it);
        }
        return s;
    }
};