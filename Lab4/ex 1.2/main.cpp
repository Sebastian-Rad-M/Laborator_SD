#include <iostream>

struct Node {
    int val;
    Node *left, *right;
};

bool checkValid(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return checkValid(root->left, minVal, root->val) && checkValid(root->right, root->val, maxVal);
}

bool isValidBST(Node* root) {
    return checkValid(root, -1e18, 1e18);
}
