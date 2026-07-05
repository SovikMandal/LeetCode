/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preOrder(TreeNode* node, int& count) {
        if(node == nullptr) return;
        count += 1;
        preOrder(node -> left, count);
        preOrder(node -> right, count);
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        TreeNode* node = root;
        int count = 0;
        preOrder(node, count);

        return count;
    }
};