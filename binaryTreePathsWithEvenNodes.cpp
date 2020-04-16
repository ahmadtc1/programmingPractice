#include <iostream>
#include <string>

struct BinaryTreeNode {
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    int val;
    int superHeroID:

    BinaryTreeNode() {
        left = nullptr;
        right = nullptr;
    }

    BinaryTreeNode(int data) {
        left = nullptr;
        right = nullptr;
        val = data;
    }
};


void paths_with_even_nodes(BinaryTreeNode* T, std::string buffer) {
    // exit if T is NULL if (!T) return;
    if (!T) {
        return;
    }

    //If the current node is even, add it to the path buffer of even nodes
    if (T -> val % 2 == 0) {
        std::string newBuffer = buffer + " -> " + std::to_string(T -> val);
        
        //Check to see if we've reached a leaf node, if we have then output the current even nodes path
        if (!T -> left && !T -> right) {
            std::cout << newBuffer << std::endl;
        }

        //If the current node only has a right child and the right child is odd, then output the current even nodes path
        else if (T -> right && !T-> left && T->right->val % 2 != 0) {
            std::cout << newBuffer << std::endl;
        }

        //If the currrent node only has a left child and the left child is odd, then output the current even nodes path
        else if (T -> left && !T -> right && T -> left -> val %2 != 0) {
            std::cout << newBuffer << std::endl;
        }

        //Continue down the left and right subtrees to see if there are more even nodes on the current path
        paths_with_even_nodes(T -> left, newBuffer);
        paths_with_even_nodes(T -> right, newBuffer);
    }

    //If the current node isn't even, restart a path down both the left and right subtrees to find an even path
    else {
        paths_with_even_nodes(T -> left, "");
        paths_with_even_nodes(T -> right, "");
    }
}
