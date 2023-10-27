#include<bits/stdc++.h>
using namespace std;  //off by 1 error ; we can't put equating thing in if condition
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    void markParents(TreeNode* root,  unordered_map<TreeNode*, TreeNode*>&p, TreeNode* target){
       
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr= q.front();
            q.pop();

            if(curr->left){
                p[curr->left]=curr;
                q.push(curr->left);
            }

            
            if(curr->right){
                p[curr->right]=curr;
                q.push(curr->right);
            }
        }

    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      
        unordered_map<TreeNode*, TreeNode*>p; //node-.parent
        markParents(root,p,target);   //Getting parents ready

        unordered_map<TreeNode*, bool>vis;
        vis[target]=true;
        queue<TreeNode*>q;
        q.push(target);
        int dis=0;

        while(!q.empty()){
            int n=q.size();
            if(dis==k) break;  //off by 1 error
            dis++;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(p[curr] && !vis[p[curr]]){
                    q.push(p[curr]);
                    vis[p[curr]]=true;
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            res.push_back(curr->val);
        }
        return res;

        
    }
};