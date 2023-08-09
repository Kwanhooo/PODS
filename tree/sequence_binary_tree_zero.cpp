//
// 二叉树 - 顺序（0起始）
// 测试
//

#include "sequence_binary_tree_zero.h"

void sequence_binary_tree_zero::test_sequence_binary_tree_zero() {
    Tree tree;
    TreeNode root;
    root.data.number = 1;
    setRoot(tree, root);

    TreeNode leftChild;
    leftChild.data.number = 2;
    insert(tree, leftChild, 0, true);

    TreeNode rightChild;
    rightChild.data.number = 3;
    insert(tree, rightChild, 0, false);

    TreeNode leftLeftChild;
    leftLeftChild.data.number = 4;
    insert(tree, leftLeftChild, 1, true);

    TreeNode leftRightChild;
    leftRightChild.data.number = 5;
    insert(tree, leftRightChild, 1, false);

    TreeNode rightLeftChild;
    rightLeftChild.data.number = 6;
    insert(tree, rightLeftChild, 2, true);

    TreeNode rightRightChild;
    rightRightChild.data.number = 7;
    insert(tree, rightRightChild, 2, false);

    std::cout << "Preorder traversal: ";
    PreorderTraverse(tree, 0);
    std::cout << std::endl;

    std::cout << "Inorder traversal: ";
    InorderTraverse(tree, 0);
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    PostorderTraverse(tree, 0);
    std::cout << std::endl;
}

