# Find All Nodes at Distance K in Binary Tree

This repository contains an optimized C++ solution to the problem of finding all nodes in a binary tree that are exactly `k` distance away from a given target node.

## Problem Statement

Given the `root` of a binary tree, a `target` node, and an integer `k`, return all the values of the nodes that have a distance `k` from the target node. The answer can be returned in any order.

## Issues in Naive Approaches

1. **Incorrect Handling of Ancestors**:
   Recursive solutions often fail to include nodes in the ancestor path or in the opposite subtrees of ancestors.

2. **Distance Miscalculation**:
   Incorrectly computing the remaining distance using recursion may lead to missing valid nodes or including nodes at the wrong depth.

3. **Redundant Checks**:
   Conditions that are already addressed during traversal (e.g., checking for exact distance separately) can introduce unnecessary complexity.

## Optimized Approach

The implemented approach uses Breadth-First Search (BFS) combined with a preprocessing step to track parent pointers of each node. This allows traversal not only down the tree but also upwards to the ancestors of the target node.

### Key Steps:
- Construct a `parent map` to allow upward traversal from the target.
- Perform BFS starting from the target node.
- At each level, check the left, right, and parent nodes.
- Stop when the current level equals the distance `k`.

## C++ Implementation

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        // Step 1: Map each node to its parent
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left) {
                parent[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent[current->right] = current;
                q.push(current->right);
            }
        }

        // Step 2: BFS from target node
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int dist = 0;

        while (!q.empty()) {
            int size = q.size();
            if (dist == k) {
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            for (int i = 0; i < size; ++i) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left && !visited[current->left]) {
                    visited[current->left] = true;
                    q.push(current->left);
                }

                if (current->right && !visited[current->right]) {
                    visited[current->right] = true;
                    q.push(current->right);
                }

                if (parent.count(current) && !visited[parent[current]]) {
                    visited[parent[current]] = true;
                    q.push(parent[current]);
                }
            }

            ++dist;
        }

        return ans;
    }
};

```
Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

Time Complexity: O(N)
Space Complexity: O(N)
