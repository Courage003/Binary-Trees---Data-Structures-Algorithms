#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {     
    int val;     TreeNode *left;     TreeNode *right;     
  TreeNode() : val(0), left(nullptr), right(nullptr) {}    
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}     
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   };

class Solution {
public:
//Iterative Postorder Traversal using 2 stacks
   
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*> st1,st2;
        if(root==NULL) return res;
         st1.push(root);

         while(!st1.empty()){
            root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->left!=NULL){
                st1.push(root->left);

            }
            if(root->right!=NULL){
                st1.push(root->right);
            }
         }
         while(!st2.empty()){
            res.push_back(st2.top()->val);
            return res;
         }
        
    }

};    