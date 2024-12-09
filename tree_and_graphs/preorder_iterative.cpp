#include <iostream>
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Left Tree -> Right Tree -> Value 
void postorder_recursion(TreeNode* root){
    if(root == NULL) return;
    postorder_recursion(root->left);
    postorder_recursion(root->right);
    cout << root->value;
}
int main(){
    //Root of the tree
    //TODO: Pass the actual binary tree
    TreeNode* root = NULL;
    postorder_recursion(root);
}