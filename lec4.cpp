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


//Postorder Traversal
vector<int> res;
vector<int> postorderTraversal(TreeNode *root)
{
    // Write your code here.
    if(root){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.push_back(root->data);
    }
    return res;
}