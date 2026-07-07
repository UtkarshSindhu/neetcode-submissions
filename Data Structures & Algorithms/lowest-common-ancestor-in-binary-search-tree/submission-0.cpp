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
    int dfs(TreeNode* root , TreeNode* p, TreeNode* q , TreeNode* &answer) {
        if(root == nullptr) return 0 ; 
        int x = dfs(root->left , p , q , answer) ; 
        if (x == 2) return 2 ;
        int y = dfs(root->right , p , q , answer) ; 
        if (y == 2) return 2 ; 
        int z = 0 ;
        if (root->val ==  p->val || root->val == q->val) z = 1 ;
        int res = x+y+z ; 
        if (res == 2 ) answer = root ; 
        return res ; 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* answer ;
        dfs( root , p,  q , answer) ; 
        return answer ; 

        
    }
};
