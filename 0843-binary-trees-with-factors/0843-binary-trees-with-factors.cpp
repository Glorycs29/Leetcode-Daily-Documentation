class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<long, long> subtreeCount;

        for (long root : arr) {
            subtreeCount[root] = 1;

            for (long factor : arr) {
                if (factor >= root) {
                    break;
                }

                if (root % factor == 0 && subtreeCount.find(root / factor) != subtreeCount.end()) {
                    subtreeCount[root] += subtreeCount[factor] * subtreeCount[root / factor];
                }
            }
        }

        long totalTrees = 0;
        for (const auto& entry : subtreeCount) {
            totalTrees += entry.second;
        }

        return totalTrees % static_cast<int>(pow(10, 9) + 7);        
    }
};