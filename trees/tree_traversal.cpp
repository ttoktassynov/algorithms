#include <iostream>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;
struct Node {
      int val;
      Node *left;
      Node *right;
      Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* insertElement(Node* root, int val)
{
    if (root == NULL) {
        return new Node(val);
    }
    Node * newNode = NULL;
    if (val < root->val) {
        root->left = insertElement(root->left, val);
    }
    if (val > root->val) {
        root->right =  insertElement(root->right, val);
    }
    return root;
}
void levelorder(Node* root){
    if (root != NULL) {
        queue<Node*> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()) {
            Node* cur_node = node_queue.front();
            cout << cur_node->val << " ";
            node_queue.pop();
            if (cur_node->left != NULL) {
                node_queue.push(cur_node->left);
            }
            if (cur_node->right != NULL) {
                node_queue.push(cur_node->right);
            }
        }
        cout << endl;
    }
}
void inorder_iterative(Node* root) {
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

void preorder_iterative(Node* root) {
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

void postorder_iterative(Node* root) {
    stack<Node*> tree_stack, out_stack;
    tree_stack.push(root);
    while (!tree_stack.empty()) {
        Node* cur_node = tree_stack.top();
        tree_stack.pop();
        out_stack.push(cur_node);
        if (cur_node->left != NULL) {
            tree_stack.push(cur_node->left);
        }
        if (cur_node->right != NULL) {
            tree_stack.push(cur_node->right);
        }
    }
    while (!out_stack.empty()) {
        cout<< out_stack.top()->val << " ";
        out_stack.pop();
    }
    cout << endl;
}

int main() {
    Node* root = insertElement(NULL, 4);
    insertElement(root, 2);
    insertElement(root, 6);
    insertElement(root, 1);
    insertElement(root, 3);
    insertElement(root, 5);
    insertElement(root, 7);
    levelorder(root);
    inorder_iterative(root);
    preorder_iterative(root);
    postorder_iterative(root);
}