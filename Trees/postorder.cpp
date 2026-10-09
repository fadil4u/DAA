#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

// builds tree from level order array, children of i are 2i+1 and 2i+2
Node* build(int a[], int i, int n) {
    if (i >= n)
        return NULL;
    Node* node = new Node;
    node->data = a[i];
    node->left = build(a, 2 * i + 1, n);
    node->right = build(a, 2 * i + 2, n);
    return node;
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

void postorder(Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int n, a[100];
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter elements level by level: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Node* root = build(a, 0, n);
    cout << "\nBinary Tree:" << endl;
    display(root, 0);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << endl;
    return 0;
}
