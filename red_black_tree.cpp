#include <bits/stdc++.h>
using namespace std;

// Enum for node colors
enum Color { RED, BLACK };

// Structure for Red-Black Tree Node
struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int value) {
        data = value;
        color = RED;       // New nodes are always RED initially
        left = right = parent = nullptr;
    }
};

class RedBlackTree {
private:
    Node* root;

    // Left Rotation
    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left != nullptr)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;

        else if (x == x->parent->left)
            x->parent->left = y;

        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    // Right Rotation
    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;

        if (y->right != nullptr)
            y->right->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;

        else if (x == x->parent->right)
            x->parent->right = y;

        else
            x->parent->left = y;

        y->right = x;
        x->parent = y;
    }

    // Fixing violations after insertion
    void fixInsert(Node* node) {
        Node* parent = nullptr;
        Node* grandparent = nullptr;

        while (node != root && node->color == RED &&
               node->parent->color == RED) {

            parent = node->parent;
            grandparent = parent->parent;

            // Parent is left child of grandparent
            if (parent == grandparent->left) {
                Node* uncle = grandparent->right;

                // Case 1: Uncle is RED
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                }
                else {
                    // Case 2: Node is right child
                    if (node == parent->right) {
                        rotateLeft(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    // Case 3: Node is left child
                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            }

            // Parent is right child of grandparent
            else {
                Node* uncle = grandparent->left;

                // Case 1: Uncle is RED
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                }
                else {
                    // Case 2: Node is left child
                    if (node == parent->left) {
                        rotateRight(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    // Case 3: Node is right child
                    rotateLeft(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            }
        }

        root->color = BLACK;
    }

public:
    RedBlackTree() {
        root = nullptr;
    }

    // Insert node like normal BST then balance
    void insert(int value) {
        Node* node = new Node(value);
        Node* parent = nullptr;
        Node* current = root;

        // Standard BST insertion
        while (current != nullptr) {
            parent = current;
            if (node->data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        node->parent = parent;

        if (parent == nullptr)
            root = node;
        else if (node->data < parent->data)
            parent->left = node;
        else
            parent->right = node;

        // Fix Red-Black Tree properties
        fixInsert(node);
    }

    // Inorder traversal
    void inorder(Node* node) {
        if (node == nullptr) return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void printTree() {
        cout << "\nInorder Traversal: ";
        inorder(root);
        cout << "\n";
    }
};

// MAIN
int main() {
    RedBlackTree rbt;

    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(25);
    rbt.insert(5);

    cout << "Red-Black Tree after insertions:";
    rbt.printTree();

    return 0;
}
