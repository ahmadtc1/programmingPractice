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
    TreeNode* increasingBST(TreeNode* root) {
        std::stack<TreeNode*> s;
        std::vector<TreeNode*> inOrder;
        
        TreeNode* current = root;
        while (!s.empty() || current) {
            if (current) {
                s.push(current);
                current = current -> left;
            }
            else {
                current = s.top();
                s.pop();
                
                inOrder.push_back(current);
                
                current = current -> right;
            }
        }
        
        for (int i = 0; i < inOrder.size(); ++i) {
            if (i < inOrder.size() - 1) {
                inOrder[i] -> left = nullptr;
                inOrder[i] -> right = inOrder[i+1];
            }
            else {
                inOrder[i] -> left = nullptr;
                inOrder[i] -> right = nullptr;
            }
        }
        
        return inOrder[0];
    }
};
