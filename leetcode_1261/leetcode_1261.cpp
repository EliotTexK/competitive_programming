#include <bits/stdc++.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
    unordered_set<int> m_hash_table; // JUST THROW A HASHTABLE AT IT
    public:
    void add_nodes_to_hashtable(TreeNode *subtree, int val) {
        m_hash_table.insert(val);
        if (subtree->left != nullptr) {
            add_nodes_to_hashtable(subtree->left, 2*val + 1);
        }
        if (subtree->right != nullptr) {
            add_nodes_to_hashtable(subtree->right, 2*val + 2);
        }
    }
    FindElements(TreeNode* root) {
        m_hash_table = unordered_set<int>();
        if (root != nullptr) {
            add_nodes_to_hashtable(root,0);
        }
    }
    bool find(int target) {
        return (bool)m_hash_table.count(target);
    }
};

int main() {
    cout << "I'm to lazy to code the test cases" << endl;
}