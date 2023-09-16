class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();

        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minHeap;

        minHeap.emplace(0,0,0);
        dist[0][0] = 0;

        int drs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while(!minHeap.empty()){
            auto [effort, x, y] = minHeap.top();
            minHeap.pop();

            if(effort > dist[x][y]) continue;
            if(x == r-1 && y == c-1) return effort;

            for(auto& dir : drs){
                int nx = x + dir[0], ny = y + dir[1];
                if(nx >=0 && nx < r && ny >=0 && ny < c){
                    int new_effort = max(effort, abs(mat[x][y] - mat[nx][ny]));
                    if(new_effort < dist[nx][ny]){
                        dist[nx][ny] = new_effort;
                        minHeap.emplace(new_effort, nx, ny);
                    }
                }
            }
        }    
        return -1;
    }
};