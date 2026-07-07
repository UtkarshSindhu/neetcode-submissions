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
    int answer = INT_MIN ;
    int dfs(TreeNode* root) {
        if(!root) return 0 ; 

        int leftsum = max (0,dfs(root->left)) ;
        int rightsum = max (0,dfs(root->right)) ;
        answer = max ({answer ,  root->val + leftsum + rightsum  }) ; 
        return max({ root->val +leftsum , root->val + rightsum }) ; 
    }
    int maxPathSum(TreeNode* root) {
         dfs(root);
         return answer ; 
    }
};
