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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer  = {};
        if(root==nullptr) return answer  ;
        deque<TreeNode*> q  ;
        q.push_back(root) ; 
        answer.push_back({root->val}) ; 
        while (!q.empty()) {
            vector<int> level ; 
            for (int i = 1 ; i<=answer[answer.size()-1].size() ; i++) {
               TreeNode* x = q.front() ; 
               if (x->left != nullptr) {
                level.push_back((x->left)->val) ; 
                q.push_back(x->left) ; 
            }
               if (x->right != nullptr) {
                level.push_back((x->right)->val) ; 
                q.push_back(x->right) ; 

            }
               q.pop_front() ; 

        }
        if (level.size()>0) answer.push_back(level);
        }
        return answer;  
    }
};
