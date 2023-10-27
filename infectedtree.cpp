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
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*>mp;
        TreeNode* target=bfs(root,mp,start);
        int time=findMax(mp,target);
        return time;
        
    }

    TreeNode* bfs(TreeNode* root, map<TreeNode*, TreeNode*>&mp, int start){
        queue<TreeNode*>q;
        q.push(root);

        TreeNode* res;
        while(!q.empty()){
            TreeNode * node=q.front();
            if(node->val==start) res=node;
            q.pop();

            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }

            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }

    int findMax(map<TreeNode*, TreeNode*>&mp, TreeNode* target){
        queue<TreeNode*>q;
        q.push(target);
        map<TreeNode*,bool>vis;
        vis[target]=1;
        int time=0;

        while(!q.empty()){
            int n=q.size();
            int f=0;
            for(int i=0;i<n;i++){
                auto node=q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    f=1;
                    vis[node->left]=1;
                    q.push(node->left);

                }

                  if(node->right && !vis[node->right]){
                    f=1;
                    vis[node->right]=1;
                    q.push(node->right);

                }
                  if(mp[node] && !vis[mp[node]]){
                    f=1;
                    vis[mp[node]]=1;
                    q.push(mp[node]);

                }
            }
            if(f) time++;
        }
        return time;
    }
};