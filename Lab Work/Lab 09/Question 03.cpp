#include <iostream>
using namespace std;

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        height = 1;
        left = right = NULL;
    }
};

int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

void updateHeight(Node* node) {
    node->height = 1 + max(height(node->left), height(node->right));
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* rebalance(Node* node) {
    updateHeight(node);

    int balance = getBalance(node);

    if (balance > 1) {
        if (getBalance(node->left) >= 0)
            return rightRotate(node);
        else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (balance < -1) {
        if (getBalance(node->right) <= 0)
            return leftRotate(node);
        else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

Node* insert(Node* node, int key) {
    if (node == NULL)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    return rebalance(node);
}

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);

    root = insert(root, 12);

    cout << "Inorder traversal of AVL tree after insertion: ";
    inorder(root);
    cout << endl;

    cout << "Height of AVL tree: " << height(root) << endl;

    cout << "Balance factors of nodes:\n";
    cout << "Node 10: " << getBalance(root) << endl;
    cout << "Node 5: " << getBalance(root->left) << endl;
    cout << "Node 15: " << getBalance(root->right) << endl;
    cout << "Node 3: " << getBalance(root->left->left) << endl;
    cout << "Node 7: " << getBalance(root->left->right) << endl;
    cout << "Node 12: " << getBalance(root->right->left) << endl;

    return 0;
}
