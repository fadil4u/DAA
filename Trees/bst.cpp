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

Node* insert(Node* root, int value) {
    if (root == NULL)
        return newNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

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
    int n, value;
    Node* root = NULL;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }
    cout << "\nBinary Search Tree:" << endl;
    display(root, 0);
    return 0;
}
