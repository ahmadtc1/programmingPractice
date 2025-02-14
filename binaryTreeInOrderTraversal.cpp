/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* current = root;
        std::stack<TreeNode* > s;
        std::vector<int> inOrder;
        while (current != nullptr || s.size() > 0) {
            while(current != nullptr) {
                s.push(current);
                current = current -> left;
            }
            current = s.top();
            s.pop();
            inOrder.push_back(current->val);
            current = current -> right;
        }
        return inOrder;
    }
};
