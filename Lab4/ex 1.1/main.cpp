#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) { 
        val = x; 
        left = NULL; 
        right = NULL; 
    }
};

Node* insertNode(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->val) root->left = insertNode(root->left, x);
    else if (x > root->val) root->right = insertNode(root->right, x);
    return root;
}

Node* buildTree(vector<int> values) {
    Node* root = NULL;
    for (int i = 0; i < values.size(); i++) {
        root = insertNode(root, values[i]);
    }
    return root;
}

bool exists(Node* root, int x) {
    if (!root) return false;
    if (root->val == x) return true;
    if (x < root->val) return exists(root->left, x);
    return exists(root->right, x);
}

Node* getMinNode(Node* root) {
    Node* curr = root;
    while (curr && curr->left) curr = curr->left;
    return curr;
}

Node* eraseNode(Node* root, int x) {
    if (!root) return root;
    if (x < root->val) root->left = eraseNode(root->left, x);
    else if (x > root->val) root->right = eraseNode(root->right, x);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = getMinNode(root->right);
        root->val = temp->val;
        root->right = eraseNode(root->right, temp->val);
    }
    return root;
}

Node* getPredecessor(Node* root, int x) {
    Node* ans = NULL;
    while (root) {
        if (root->val < x) {
            ans = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return ans;
}

Node* getSuccessor(Node* root, int x) {
    Node* ans = NULL;
    while (root) {
        if (root->val > x) {
            ans = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ans;
}
