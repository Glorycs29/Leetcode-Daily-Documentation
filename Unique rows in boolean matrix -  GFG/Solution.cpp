class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        vector<vector<int>> ans;
        unordered_map<string, vector<int>> mp;
        for(int i=0;i<row;i++){
            string str = "";
            vector<int> temp;
            for(int j=0;j<col;j++){
                str += to_string(M[i][j]);
                temp.push_back(M[i][j]);
            }
            if(mp[str].empty()){
                mp[str] = temp;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
