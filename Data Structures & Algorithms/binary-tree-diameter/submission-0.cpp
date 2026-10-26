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

        auto left_depth = max_depth(root->left, depth +1 );
        auto right_depth = max_depth(root->right, depth+1 );

        return std::max(left_depth,right_depth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }

        int diameter = max_depth(root->right,0) + max_depth(root->left,0);
        int sub_tree_max_diameter = std::max(diameterOfBinaryTree(root->right),diameterOfBinaryTree(root->left));
        return std::max(diameter,sub_tree_max_diameter);
    }
};
