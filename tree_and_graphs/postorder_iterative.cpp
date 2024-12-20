#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include "TreeNode.h"

// Left Tree -> Right Tree -> Value 
/**
 * Implementation using 2 stacks. First stack to keep track of left and right subtrees of a node.
 * And second stack is to store the root value that has to be printed at the end of the traversal. 
 */
void postorder_iterative(TreeNode* root){
    stack<TreeNode*> value; 
    stack<TreeNode*> traversal;
    traversal.push(root);
    while(!traversal.empty()){
        TreeNode* curr_val = traversal.top();
        traversal.pop();
        value.push(curr_val);
        if(curr_val ->left != NULL)
            traversal.push(curr_val->left);
        if(curr_val->right != NULL)
            traversal.push(curr_val->right);
    }

    // Printing the traversal.
    while(!value.empty()){
        cout << value.top() << " ";
        value.pop();
    }
}
int main(){
    //TODO: Give non null root.
    TreeNode* root = NULL;
    postorder_iterative(root);
}
