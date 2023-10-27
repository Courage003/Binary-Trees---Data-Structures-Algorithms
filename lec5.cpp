#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:

//Level Order Traversal of a Binary Tree
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            vector<int>ds;
            for(int i=0;i<n;i++){
                TreeNode* node= q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                ds.push_back(node->val);

            }
            res.push_back(ds);
        }
        return res;
        
    }
};