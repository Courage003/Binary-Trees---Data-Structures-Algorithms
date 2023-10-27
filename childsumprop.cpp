#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution{
    public:
    
    void sumProp(Node *root){
        if(!root) return;
        int child=0;
        if(root->left) child+=root->left->data;
        if(root->right) child+=root->right->data;
        
        if(child>=root->data) root->data=child;
        else{
            if(root->left) root->left->data=root->data;
            else if(root->right) root->right->data=root->data;
        }
        
        sumProp(root->left);
        sumProp(root->right);
        
        int tot=0;
        if(root->left) tot+=root->left->data;
        if(root->right) tot+=root->right->data;
        if(root->left || root->right) root->data=tot;  //Backtracking condition
    }

};  