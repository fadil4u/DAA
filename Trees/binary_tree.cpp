#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int value) {
    Node* n = new Node;
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

// reads preorder input, -1 means no child
Node* create() {
    int value;
    cin >> value;
    if (value == -1)
        return NULL;
    Node* root = newNode(value);
    root->left = create();
    root->right = create();
    return root;
}

// prints the tree sideways (right subtree on top)
void display(Node* root, int level) {
    if (root == NULL)
        return;
    display(root->right, level + 1);
    for (int i = 0; i < level; i++)
        cout << "     ";
    cout << root->data << endl;
    display(root->left, level + 1);
}

int main() {
    cout << "Enter elements in preorder (-1 for no child):" << endl;
    Node* root = create();
    cout << "\nBinary Tree:" << endl;
    display(root, 0);
    return 0;
}
