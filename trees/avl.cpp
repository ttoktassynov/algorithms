#include <iostream>
#include <cmath>
#include <stack>
#include <memory>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    int height;
    Node(int val) : val(val), left(NULL), right (NULL), height(0) {}
};

int getHeight(Node* node) {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

Node* rotate_ll(Node* root) {
    Node* parent = root->right;
    Node* T2 = parent->left;

    parent->left = root;
    root->right = T2;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;

    return parent;
}

Node* rotate_rr(Node* root) {
    Node* parent = root->left;
    Node* T2 = parent->right;

    parent->right = root;
    root->left = T2;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;

    return parent;
}

Node* insertElement(Node* root, int val)
{
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->val) {
        root->left = insertElement(root->left, val);
    }
    if (val > root->val) {
        root->right =  insertElement(root->right, val);
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int balance = getHeight(root->left) - getHeight(root->right);

    if (balance > 1 && val < root->left->val) {
        return rotate_rr(root);
    }
    if (balance < - 1 && val > root->right->val) {
        return rotate_ll(root);
    }
    if (balance > 1 && val > root->left->val) {
        root->left = rotate_ll(root->left);
        return rotate_rr(root);
    }
    if (balance < - 1 && val < root->right->val) {
        root->right = rotate_rr(root->right);
        return rotate_ll(root);
    }
    return root;
}

void inorderTraversal(Node* root) {
    stack<Node*> tree_stack;
    while (root != NULL || !tree_stack.empty()) {
        while (root != NULL) {
            tree_stack.push(root);
            root = root->left;
        }
        Node* cur_node = tree_stack.top();
        tree_stack.pop();
        cout << cur_node->val << " ";
        root = cur_node->right;
    }
    cout << endl;
}
void preorderTraversal(Node* root) {
    stack<Node*> tree_stack;
    tree_stack.push(root);
    while (!tree_stack.empty()) {
        Node* cur_node = tree_stack.top();
        tree_stack.pop();
        cout << cur_node->val << " ";
        if (cur_node->right != NULL) {
            tree_stack.push(cur_node->right);
        }
        if (cur_node->left != NULL) {
            tree_stack.push(cur_node->left);
        }
    }
    cout << endl;
}
int main() {
    Node *root = insertElement(NULL, 10);
    insertElement(root, 7);
    insertElement(root, 15);
    insertElement(root, 3);
    insertElement(root, 18);
    insertElement(root, 16);
    preorderTraversal(root);
}