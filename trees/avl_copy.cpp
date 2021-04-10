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
void rotate_ll(Node* &root, Node* &parent) {
    root->left = parent->right;
    parent->right = root;
    swap(root, parent);
}
void rotate_lr(Node* &root, Node* &parent, Node* &gr_child_right) {
    root->left = gr_child_right;
    parent->right = NULL;
    gr_child_right->left = parent;
    rotate_ll(root, gr_child_right);
}
void rotate_rr(Node* &root, Node* &parent) {
    root->right = parent->left;
    parent->left = root;
    swap(root, parent);
}
void rotate_rl(Node* &root, Node* &parent, Node* &gr_child_left) {
    root->right = gr_child_left;
    parent->left = NULL;
    gr_child_left->right = parent;
    rotate_rr(root, gr_child_left);
}

Node* insertElement(Node* root, int val)
{
    if (root == NULL) {
        return new Node(val);
    }
    Node * newNode = NULL;
    if (val < root->val) {
        root->left = insertElement(root->left, val);
        root->height = max(root->height, root->left->height + 1);
        
        int left_hgt = root->left->height;
        int right_hgt = (root->right !=  NULL) ? root->right->height : -1;
        if (abs(left_hgt -right_hgt) > 1) {
            Node* parent = root->left;
            Node* gr_child_left = parent->left;
            Node* gr_child_right = parent->right;

            if (gr_child_left != NULL && gr_child_left->val == val){
                rotate_ll(root, parent);
            }
            else if (gr_child_right != NULL && gr_child_right->val == val) {
                rotate_lr(root, parent, gr_child_right);
            }
        }
    }
    if (val > root->val) {
        root->right =  insertElement(root->right, val);
        root->height = max(root->height, root->right->height + 1);

        int right_hgt = root->right->height;
        int left_hgt = (root->left !=  NULL) ? root->left->height : -1;
        if (abs(left_hgt -right_hgt) > 1) {
            Node* parent = root->right;
            Node* gr_child_left = parent->left;
            Node* gr_child_right = parent->right;
            
            if (gr_child_left != NULL && gr_child_left->val == val){
                rotate_rl(root, parent, gr_child_left);
            }
            else if (gr_child_right != NULL && gr_child_right->val == val) {
                rotate_rr(root, parent);
            }
        }
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
    insertElement(root, 5);
    preorderTraversal(root);
}