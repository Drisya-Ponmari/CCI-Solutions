#include <iostream>
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//  Value ->Left Tree -> Right Tree
void preorder_recursion(TreeNode* root){
    if(root == NULL) return;
    cout << root->value;
    preorder_recursion(root->left);
    preorder_recursion(root->right);
}
int main(){
    //Root of the tree
    //TODO: Pass the actual binary tree
    TreeNode* root = NULL;
    preorder_recursion(root);
}