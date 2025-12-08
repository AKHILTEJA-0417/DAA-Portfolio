#include <bits/stdc++.h>
using namespace std;

// -------------------------
// Node structure
// -------------------------
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        left = right = nullptr;
    }
};

// -------------------------
// Insert node in BST
// -------------------------
Node* insertNode(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);

    return root; // unchanged root
}

// -------------------------
// Search in BST
// -------------------------
bool searchNode(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->key == key) return true;

    if (key < root->key)
        return searchNode(root->left, key);
    else
        return searchNode(root->right, key);
}

// -------------------------
// Find minimum node
// -------------------------
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// -------------------------
// Delete a node in BST
// -------------------------
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: One child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right); // inorder successor
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// -------------------------
// Traversals
// -------------------------
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

// -------------------------
// MAIN (Demo)
// -------------------------
int main() {
    Node* root = nullptr;

    // Insert elements
    vector<int> values = {50, 30, 70, 20, 40, 60, 80};
    for (int x : values)
        root = insertNode(root, x);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    cout << "Searching 40: " << (searchNode(root, 40) ? "Found" : "Not Found") << "\n";

    // Delete example
    root = deleteNode(root, 30);

    cout << "Inorder After Deleting 30: ";
    inorder(root);
    cout << "\n";

    return 0;
}
