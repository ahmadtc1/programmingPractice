public:
    int minDiffInBST(TreeNode* root) {
        std::stack<TreeNode* > s;
        std::vector<int> inOrder;
        TreeNode* current = root;
        while (current != nullptr || s.size() != 0) {
            while (current != nullptr) {
                s.push(current);
                current = current -> left;
            }
            current = s.top();
            s.pop();
            inOrder.push_back(current -> val);
            current = current -> right;
        }
        int minDifference = INT_MAX;
        for (int i = 0; i < inOrder.size(); i++) {
            for (int j = i + 1; j < inOrder.size(); j++) {
                if (inOrder[i] - inOrder[j] < 0) {
                    int difference = (inOrder[j] - inOrder[i]);
                    if (difference < minDifference) {
                        minDifference = difference;
                    }
                }
                else {
                    int difference = inOrder[i] - inOrder[j];
                    if (difference < minDifference) {
                        minDifference = difference;
                    }
                }
            }
        }
        return minDifference;
    }
};
