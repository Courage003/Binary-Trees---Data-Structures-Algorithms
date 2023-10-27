#include<bits/stdc++.h>
using namespace std;

    template <typename T>


    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

    //PRE-Order Traversal (root left right)

vector<int>res;
vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.

    
   if(root){

    
    res.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);

   }
   return res;
}


