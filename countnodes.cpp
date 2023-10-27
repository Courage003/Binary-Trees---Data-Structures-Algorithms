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
    
    int countNodes(TreeNode* root) {
       if(!root) return 0;

       int lh=heightleft(root);
       int rh=heightright(root);

       if(lh==rh) return (1<<lh)-1;  //2 raised to the power lh

       return 1+countNodes(root->left)+countNodes(root->right);
        
    }

    int heightleft(TreeNode* node){
        int ht=0;
        while(node){
            ht++;
            node=node->left;
        }
        return ht;
    }

    int heightright(TreeNode* node){
        int ht=0;
        while(node){
            ht++;
            node=node->right;
        }
        return ht;
    }
};