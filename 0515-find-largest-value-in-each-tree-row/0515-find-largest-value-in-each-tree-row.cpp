/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
       queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        if(!root) return ans;
        while(!q.empty()){
            int level = q.size();
            int maxi = INT_MIN;

            for(int i=0; i<level; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                maxi = max(maxi, temp->val);
            }
            ans.push_back(maxi);
        }

        return ans;
    }
};