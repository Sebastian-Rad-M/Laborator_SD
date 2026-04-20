#include <string>
#include <sstream>

struct Node {
    int val;
    Node *left, *right;
    Node(int x) { val = x; left = NULL; right = NULL; }
};

void serializeNode(Node* root, std::ostringstream& outStream) {
    if (!root) {
        outStream << "# ";
        return;
    }
    outStream << root->val << " ";
    serializeNode(root->left, outStream);
    serializeNode(root->right, outStream);
}

std::string serializeTree(Node* root) {
    std::ostringstream outStream;
    serializeNode(root, outStream);
    return outStream.str();
}

Node* deserializeNode(std::istringstream& inStream) {
    std::string currentVal;
    inStream >> currentVal;
    if (currentVal == "#") return NULL;
    Node* root = new Node(std::stoi(currentVal));
    root->left = deserializeNode(inStream);
    root->right = deserializeNode(inStream);
    return root;
}

Node* deserializeTree(std::string data) {
    std::istringstream inStream(data);
    return deserializeNode(inStream);
}
