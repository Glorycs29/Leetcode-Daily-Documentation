class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> sample;

        //Step 1 (Check Approach)
        for (int i = 0; i < adjacentPairs.size(); i++) {
            int a = adjacentPairs[i][0];
            int b = adjacentPairs[i][1];
            sample[a].push_back(b);
            sample[b].push_back(a);
        }
        
        //Step 2 (Check Approach)
        int first = 0;
        for (auto it = sample.begin(); it != sample.end(); it++) {
            if (it->second.size() == 1) {
                first = it->first;
                break;
            }
        }
        
        //Step 3 (Check Approach)
        vector<int> nums;
        nums.push_back(first);
        int prev = first;
        int i = 1;
        while (i <= adjacentPairs.size()) {
            int next = sample[first][0];
            if (next == prev) {
                next = sample[first][1];
            }
            nums.push_back(next);
            i++;
            int temp = first;
            first = next;
            prev = temp;
        }
        
        return nums;
    }
};

