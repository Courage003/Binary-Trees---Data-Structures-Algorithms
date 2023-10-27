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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        int n=inorder.size();
        int m=postorder.size();

        if(m!=n) return NULL;

        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }

        return buildTree1(inorder,0,n-1,postorder,0,m-1,mp);

        
    }

    TreeNode* buildTree1(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int prestart, int preend, map<int,int>&mp){
        if(instart>inend || prestart>preend) return NULL;

        TreeNode* root= new TreeNode(postorder[preend]);
        int inroot=mp[postorder[preend]];

        int numsleft=inroot-instart;

        root->left=buildTree1(inorder,instart,inroot-1,postorder,prestart, prestart+numsleft-1,mp);
        root->right=buildTree1(inorder,inroot+1,inend,postorder,prestart+numsleft,preend-1,mp);

        return root;
    }
};