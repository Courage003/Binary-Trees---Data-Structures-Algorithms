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


  bool getpath(TreeNode * root, vector<int>v, int x){
    if(!root) return false;
                                                    //locating around every branch and deleting if any of the sides return false
    v.push_back(root->val);

    if(root->val==x) return true;

    if(getpath(root->left,v,x) || getpath(root->right,v,x)) return true;

    v.pop_back();
    return false;
  }

  vector<int> solve(TreeNode* A, int x){
    vector<int>res;
    if(!A) return res;
    getpath(A,res,x);
    return res;
  }

