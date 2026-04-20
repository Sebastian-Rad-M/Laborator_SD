#include <iostream>

struct Node {
    int val;
    Node *left, *right;
};

Node *firstNode = NULL, *secondNode = NULL, *prevNode = NULL;

void dfs(Node* root) {
    if (!root) return;
    dfs(root->left);
    if (prevNode && root->val < prevNode->val) {
        if (!firstNode) firstNode = prevNode;
        secondNode = root;
    }
    prevNode = root;
    dfs(root->right);
}

void recoverTree(Node* root) {
    firstNode = NULL;
    secondNode = NULL;
    prevNode = NULL;
    dfs(root);
    if (firstNode && secondNode) {
        int tempVal = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = tempVal;
    }
}
