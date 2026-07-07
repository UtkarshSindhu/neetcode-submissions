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
    int count = 0 ;
    void dfs(TreeNode *root ,int  highest ){
        if (!root) return ; 
        if (root->val >= highest) count++ ; 
        dfs(root->left , max(root->val , highest)) ; 
        dfs(root->right , max (root->val , highest)) ; 
    }
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0 ; 
        dfs(root , -101 ) ; 
        return count ; 
    }
};
