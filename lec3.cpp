#include<bits/stdc++.h>
using namespace std;


    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

    //Inorder Traversal

vector<int> res;
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    if(root){
        getInOrderTraversal(root->left);
        res.push_back(root->data);
        getInOrderTraversal(root->right);

    }
    return res;
}