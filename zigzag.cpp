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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;
        queue<TreeNode* >q;
        q.push(root);
        bool LtoR=true;

        while(!q.empty()){
            int n=q.size();
            vector<int>row(n);
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();

                int id=(LtoR) ? i : n-1-i;
                row[id]=node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);    
            }
            LtoR=!LtoR;  //changing flag from 0 to 1 after pushing into ds
            res.push_back(row);
        }
        return res;
        
    }
};