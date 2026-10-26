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
    int max_depth(TreeNode* root, int depth){
        if(!root){
            return depth;
        }

        auto left_depth = max_depth(root->left, depth +1);
        auto right_depth = max_depth(root->right, depth+1);
        return std::max(left_depth,right_depth);
    }
    int maxDepth(TreeNode* root) {
        return max_depth(root,0);
    }
};
