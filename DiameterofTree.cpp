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
    int heightofTree(TreeNode* root, int &maxi){
        if(root==NULL) return 0;

        int l=heightofTree(root->left,maxi);
        int r=heightofTree(root->right,maxi);

        maxi=max(maxi,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        heightofTree(root,maxi);
        return maxi;
        
    }
};