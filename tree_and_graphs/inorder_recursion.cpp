#include <iostream>
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Left Tree -> Value -> Right Tree
void inorder_recursion(TreeNode* root){
    if(root == NULL) return;
    inorder_recursion(root->left);
    cout << root->value;
    inorder_recursion(root->right);
}
int main(){
    //Root of the tree
    //TODO: Pass the actual binary tree
    TreeNode* root = NULL;
    inorder_recursion(root);
}