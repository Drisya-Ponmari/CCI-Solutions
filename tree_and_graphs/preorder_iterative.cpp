#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include "TreeNode.h"
using namespace std;

//  Value  -> Left Tree -> Right Tree
/**
 * Implemented using 'STACK'
 * Similar to 'inorder_iterative' method. Instead of printing value while popping, do it while pushing. 
 */
void preorder_iterative(TreeNode* root){
    if(root == NULL) return;
    stack<TreeNode*> preorder_stack;
    preorder_stack.push(new TreeNode(0));

    TreeNode* itr = root;
    while(preorder_stack.size() > 1){
        if(itr == NULL){
            itr = preorder_stack.top()->right;
            preorder_stack.pop();
        }else{
            cout << itr->value;
            preorder_stack.push(itr);
            itr = itr->left;
        }
    }
}
int main(){
    //Root of the tree
    //TODO: Pass the actual binary tree
    TreeNode* root = NULL;
    preorder_iterative(root);
}