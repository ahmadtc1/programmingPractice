#include <iostream>
#include <stack>
#include <vector>


struct BinaryTreeNode {
	BinaryTreeNode* right;
	BinaryTreeNode* left;
	int value;
}

bool isBinarySearchTree(BinaryTreeNode* T) {
	std::stack<BinaryTreeNode*> s;
	std::vector<int> preOrder;
	s.push(T);
	while (!s.empty()) {
		BinaryTreeNode* current = s.top();
		preOrder.push_back(current -> data);
		if (current -> right) {
			s.push(current -> right);
		}
		if (current -> left) {
			s.push(current -> left);
		}
	}
	bool isAscending = true;
	for (int i = 0; i < preOrder.size() - 1; ++i) {
		isAscending = isAscending && preOrder[i] <= preOrder[i + 1];
	}
	return isAscending;
}

