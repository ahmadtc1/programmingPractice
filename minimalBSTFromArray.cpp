BinaryTreeNode* createMinimalBST(std::vector<int> data, int left, int right) {
    if (right < left) {
        return nullptr;
    }
    else {
        int middle = (left + right) / 2;
        BinaryTreeNode* root = new BinaryTreeNode(data[middle]);
        root -> left = createMinimalBST(data, left, middle - 1);
        root -> right = createMinimalBST(data, middle + 1, right);
        return root;
    }
}

BinaryTreeNode* createMinimalBST(std::vector<int> data) {
    return createMinimalBST(data, 0, data.size() - 1);
}

void inOrderTraversal(BinaryTreeNode* t) {
    if (!t) {
        return;
    }

    inOrderTraversal(t -> left);

    std::cout << t -> value << " -> ";

    inOrderTraversal(t -> right);
}
