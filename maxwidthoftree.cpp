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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        int res=0;
        while(!q.empty()){
            int s,e;
            int n=q.size();
            int minid=q.front().second;
            for(int i=0;i<n;i++){
                long long cur_id=q.front().second-minid;
                TreeNode * node=q.front().first;
                q.pop();
                if(i==0) s=cur_id;
                if(i==n-1) e=cur_id;

                if(node->left)
                    q.push({node->left,cur_id*2+1});
                
                if(node->right)
                    q.push({node->right,cur_id*2+2});
                

            }
            res=max(res,e-s+1);
        }
        return res;
        
    }
};