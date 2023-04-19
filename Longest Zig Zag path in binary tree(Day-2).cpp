


class Solution {
public:

    //  https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/solutions/3433060/image-explanation-easy-complete-intuition-c-java-python/
    int maxLength=0;
    void maxZigZagNode(TreeNode* node, int dir, int curLength){
        if(!node)return;
        maxLength = max(maxLength, curLength);
        maxZigZagNode(node->left, 0, dir ? curLength + 1 : 1); // if direction is 0 (means it needs left otherwise right)
        maxZigZagNode(node->right, 1, dir ? 1 : curLength + 1);
    }

    int longestZigZag(TreeNode* root) {
        maxZigZagNode(root, 0, 0);
        maxZigZagNode(root, 1, 0);
        return maxLength;
    }
};
