#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include "TreeNode.h"
using namespace std;

// Left Tree -> Value -> Right Tree
/**
 * Implementation is via 'STACK' 
 * Logic: Push the left children to stack till it reaches NULL. Once the Left children are emtpy, pop the stack an move to right. Repeat.
 */
void inorder_iterative(TreeNode* root){
    if(root == NULL) return;
    stack<TreeNode*> inorder_stack;
    
    TreeNode* itr = root;
    while(!inorder_stack.empty()){
        if(itr == NULL){
            TreeNode* stack_top = inorder_stack.top();
            cout << stack_top->value;
            inorder_stack.pop();
            itr = stack_top -> right;
        }else{
            // Push till finding a NULL node. 
            inorder_stack.push(itr);
            itr = itr ->left;
        }
    }
}
int main(){
    //Root of the tree
    //TODO: Pass the actual binary tree
    TreeNode* root = NULL;
    inorder_iterative(root);
}