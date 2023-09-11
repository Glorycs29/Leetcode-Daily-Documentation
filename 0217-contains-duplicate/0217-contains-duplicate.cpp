// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//          // Find the intersection point of the two runners.
//         set<int> s;
//         for(auto x:nums){
//             if(s.find(x)!=s.end())return true;
//             else s.insert(x);
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1] == nums[i]) return true;
        }

        return false;
    }
};