#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(NULL), right (NULL) {}
};

Node* minElement(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
Node* maxElement(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}
Node* searchElement(Node* root, int val) {
    if (root == NULL ) {
        return NULL;
    }
    if (val < root->val) {
        return searchElement(root->left, val);
    }
    if (val > root->val) {
        return searchElement(root->right, val);
    }
    return root;
}

Node* getParent(Node* parent, Node* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    if (val < root->val) {
        return getParent(root, root->left, val);
    }
    if (val > root->val) {
        return getParent(root, root->right, val);
    }
    return parent;
}
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}
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

Node* getInorderSuccessor(Node* root, Node* node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->right != NULL) {
        Node* curNode = node->right;
        while (curNode->left != NULL) {
            curNode = curNode->left;
        }
        return curNode;
    }
    else {
        Node* curNode = root;
        Node* parent = NULL;
        while (curNode != node) {
            if (node->val < curNode->val) {
                parent = curNode;
                curNode = curNode->left;
            }
            if (node->val > curNode->val) {
                curNode = curNode->right;
            }
        }
        return parent;
    }
}
Node* deleteElement(Node* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    if (val < root->val) {
        root->left = deleteElement(root->left, val);
    }
    else if (val > root->val) {
        root->right =  deleteElement(root->right, val);
    }
    else {
        if (root->left != NULL && root->right != NULL) {
            Node* inorderSucc = minElement(root->right);
            root->val = inorderSucc->val;
            root->right = deleteElement(root->right, inorderSucc->val);
            return root;
        }
        else if (root->left != NULL) {
            Node* out = root->left;
            delete root;
            return out;
        }
        else if (root->right != NULL) {
            Node * out = root->right;
            delete root;
            return out;
        }
        else {
            return NULL;
        }
    }
    return root;
}
int main() {
    Node* root = insertElement(NULL, 10);
    insertElement(root, 7);
    insertElement(root, 15);
    insertElement(root, 3);
    insertElement(root, 9);
    insertElement(root, 12);
    insertElement(root, 17);
    insertElement(root, 2);
    insertElement(root, 5);
    insertElement(root, 11);
    insertElement(root, 14);
    insertElement(root, 16);
    insertElement(root, 101);
    inorderTraversal(root);
    cout << endl;
    /*
    Node* node15 = searchElement(root, 15);
    Node* node2 = searchElement(root, 2);
    Node* node14 = searchElement(root, 14);
    Node* node202 = searchElement(root, 202);
    cout << node15 << endl;
    cout << node2 << endl;
    cout << node14 << endl;
    cout << node202 << endl;

    printf("inorderTraversal successor of %d is %d\n", 15, getInorderSuccessor(root, node15)->val);
    printf("inorderTraversal successor of %d is %d\n", 2, getInorderSuccessor(root, node2)->val);
    printf("inorderTraversal successor of %d is %d\n", 14, getInorderSuccessor(root, node14)->val);
    printf("parent of 3 is %d\n", getParent(NULL, root, 3)->val);
    printf("parent of 101 is %d\n", getParent(NULL, root, 101)->val);
    inorderTraversal(root);
    cout << endl;
    root = deleteElement(root, 101);
    inorderTraversal(root);
    cout << endl;

    cout << minElement(root)->val << " " << maxElement(root)->val << endl;*/
    
    
}