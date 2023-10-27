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

 //Iterative Preorder Traversal
 
class Solution {
public:
    vector<int>res;
    vector<int> preorderTraversal(TreeNode* root) {
    if(root==NULL) return res;
    stack<TreeNode *>st;
    st.push(root);

    while(!st.empty()){
        root=st.top();
        st.pop();
        if(root->right!=NULL){
            res.push_back(root->right->val);
        }
          if(root->left!=NULL){
            res.push_back(root->left->val);
        }
    }
    return res;
        
    }
};


