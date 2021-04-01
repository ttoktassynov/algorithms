#include <iostream>
#include <unordered_set>

using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    void dfs(TreeNode* root, unordered_set<int>& visited) {
        if (root == nullptr) {
            return;
        }
        visited.insert(root->val);
        if (root->left != nullptr && !visited.count(root->left->val)) {
            dfs(root->left, visited);
        }
        if (root->right != nullptr && !visited.count(root->right->val)) {
            dfs(root->right, visited);
        }
        cout << root->val << " ";
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(3);
    root->left = left;
    root->right = right;

    Solution s;
    unordered_set<int> visited;
    cout << " test "; 
    s.dfs(root, visited);
}   