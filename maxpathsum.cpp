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
    int gettree(TreeNode* root, int &maxi){
        if(root==NULL) return 0;
        int l=max(0,gettree(root->left,maxi));
        int r=max(0,gettree(root->right,maxi));
        maxi=max(maxi,root->val+l+r);
        return root->val+ max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        gettree(root,maxi);
        return maxi;
    }
};