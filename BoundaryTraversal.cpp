#include<bits/stdc++.h>
using namespace std;



    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };



bool isLeaf(TreeNode<int> * root){
  if(root->left || root->right){
    return false;
  }
  return true;
}


void addLeftB(TreeNode<int> *root, vector<int> &res){
    TreeNode<int> * cur= root->left;
   

    while(cur){
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) cur=cur->left;
        else cur=cur->right;
    }
}  //adding left boundary excluding leaves

void addRightB(TreeNode<int> *root, vector<int> &res){
    TreeNode<int> * cur=root->right;
    vector<int> temp;
    while(cur){
        if(!isLeaf(cur)) temp.push_back(cur->data);
        if(cur->right) cur=cur->right;
        else cur=cur->left;
    }

    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}  //adding right boundary excluding leaves in reverse order

void addLeaves(TreeNode<int> *root, vector<int>&res){
    if(isLeaf(root)){
        res.push_back(root->data);
    return;

    } 

    if(root->left) addLeaves(root->left,res);
    if(root->right) addLeaves(root->right,res);
}  // adding leaf nodes by inorder traversal;


vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int>ds;
    if(!root) return ds;
    if(!isLeaf(root)) ds.push_back(root->data);
    addLeftB(root,ds);
    addLeaves(root,ds);
    addRightB(root,ds);

    return ds;
}
