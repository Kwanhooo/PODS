//
// 二叉树 - 顺序（1起始）
// 测试
//

#include "sequence_binary_tree.h"

void sequence_binary_tree::test_sequence_binary_tree() {
    Tree tree;
    TreeNode root;
    root.data.number = 1;
    setRoot(tree, root);

    TreeNode leftChild;
    leftChild.data.number = 2;
    insert(tree, leftChild, 1, true);

    TreeNode rightChild;
    rightChild.data.number = 3;
    insert(tree, rightChild, 1, false);

    TreeNode leftLeftChild;
    leftLeftChild.data.number = 4;
    insert(tree, leftLeftChild, 2, true);

    TreeNode leftRightChild;
    leftRightChild.data.number = 5;
    insert(tree, leftRightChild, 2, false);

    TreeNode rightLeftChild;
    rightLeftChild.data.number = 6;
    insert(tree, rightLeftChild, 3, true);

    TreeNode rightRightChild;
    rightRightChild.data.number = 7;
    insert(tree, rightRightChild, 3, false);

    std::cout << "Preorder traversal: ";
    PreorderTraverse(tree, 1);
    std::cout << std::endl;

    std::cout << "Inorder traversal: ";
    InorderTraverse(tree, 1);
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    PostorderTraverse(tree, 1);
    std::cout << std::endl;
}
