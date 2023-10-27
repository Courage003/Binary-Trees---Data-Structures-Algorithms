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

    //Iterative Inorder Traversal
    vector<int>res;
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node=root;
        vector<int>res;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()) break;
                node=st.top();
                st.pop();
                res.push_back(node->val);
                node=node->right;

            }
        }
        return res;
        
    }
};