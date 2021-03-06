#include <iostream>
#include <stack>
#include "TreeNode.h"
using namespace std;

void postorderIterative(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> stk;
    TreeNode *curr = root, *prev = nullptr;
    while (curr || !stk.empty()) {
        if (curr) {
            stk.push(curr);
            curr = curr->left;
        } else {
            TreeNode* temp = stk.top();
            if (temp->right && temp->right != prev) {
                curr = temp->right;
            } else {
                cout << temp->val << ' ';  // visit
                stk.pop();
                prev = temp;
            }
        }
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    postorderIterative(root);
    cout << endl;
    return 0;
}
