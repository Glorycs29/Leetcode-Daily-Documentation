class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        int n = groupSizes.size();
        vector<vector<int>> groups(n + 1);
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
        {
            groups[groupSizes[i]].push_back(i);
            if(groups[groupSizes[i]].size() == groupSizes[i])
                ans.push_back(move(groups[groupSizes[i]]));
        }

        return ans;
    }
};