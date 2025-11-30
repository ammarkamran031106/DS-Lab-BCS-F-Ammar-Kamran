
#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    int score; // score is optional here
};

struct Node {
    Student data;
    int height;
    Node* left;
    Node* right;

    Node(Student s) {
        data = s;
        height = 1;
        left = right = NULL;
    }
};

class AVL {
public:
    Node* root;
    AVL() { root = NULL; }

    int getHeight(Node* n) {
        if (!n) return 0;
        return n->height;
    }

    void updateHeight(Node* n) {
        if (n != NULL)
            n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    }

    int getBalance(Node* n) {
        if (!n) return 0;
        return getHeight(n->left) - getHeight(n->right);
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

    Node* insert(Node* node, Student s) {
        if (node == NULL)
            return new Node(s);

        if (s.id < node->data.id)
            node->left = insert(node->left, s);
        else if (s.id > node->data.id)
            node->right = insert(node->right, s);
        else
            return node;

        updateHeight(node);

        int balance = getBalance(node);

        if (balance > 1 && s.id < node->left->data.id)
            return rightRotate(node);

        if (balance < -1 && s.id > node->right->data.id)
            return leftRotate(node);

        if (balance > 1 && s.id > node->left->data.id) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && s.id < node->right->data.id) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void insert(Student s) {
        root = insert(root, s);
    }
};

// ---------- Inorder Traversal ----------
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data.id << "(" << root->data.name << ") ";
    inorder(root->right);
}

// ---------- Main Function ----------
int main() {
    Node* root = NULL;
    AVL tree;

	tree.insert({10, "S1", 0});
	tree.insert({20, "S2", 0});
	tree.insert({30, "S3", 0});
	tree.insert({40, "S4", 0});
	tree.insert({50, "S5", 0});
	tree.insert({15, "newStudent", 0});
	
	cout << "Traversal of balanced AVL tree: "<<endl;
	inorder(tree.root);
	
	cout << "Height of AVL tree: " << tree.getHeight(tree.root) << endl;

    return 0;
}
