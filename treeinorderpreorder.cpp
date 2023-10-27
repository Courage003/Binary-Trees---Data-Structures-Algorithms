#include<bits/stdc++.h>
using namespace std;


//Constructing unique binary tree from inorder and preorder
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        int n=inorder.size();
        int m=preorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root= buildTree1(preorder,0,m-1,inorder,0,n-1,mp);
        return root;
        
    }

    TreeNode* buildTree1(vector<int>& preorder,int prestart, int preend, vector<int>& inorder, int instart, int inend, map<int,int>&mp){
        if(instart>inend || prestart>preend) return NULL;

        TreeNode* root= new TreeNode(preorder[prestart]);
        int inroot=mp[root->val]; //locating root in the inorder list
        int numsleft= inroot-instart;

        root->left=buildTree1(preorder, prestart+1,prestart+numsleft,inorder, instart,inroot-1,mp);
        root->right=buildTree1(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,mp);

        return root;


    }
};