//
// 树(森林)的孩子表示法
// 测试
//

#include <iostream>
#include "child_model_tree.h"

void child_model_tree::test_child_model_tree() {
    // Create a tree
    Tree tree;
    TreeNode root_node;
    root_node.data.number = 1;
    root_node.firstChild = nullptr;
    setTreeRoot(tree, root_node);

    TreeNode node2, node3;
    node2.data.number = 2;
    node2.firstChild = nullptr;
    insert(tree, node2, 0);

    node3.data.number = 3;
    node3.firstChild = nullptr;
    insert(tree, node3, 0);

    TreeNode node4, node5;
    node4.data.number = 4;
    node4.firstChild = nullptr;
    insert(tree, node4, 1);

    node5.data.number = 5;
    node5.firstChild = nullptr;
    insert(tree, node5, 1);

    TreeNode node6;
    node6.data.number = 6;
    node6.firstChild = nullptr;
    insert(tree, node6, 2);

    std::cout << "Tree elements (pre-order): ";
    preOrder(tree, 0);
    std::cout << std::endl;

    std::cout << "Tree elements (post-order): ";
    postOrder(tree, 0);
    std::cout << std::endl;

    std::cout << "Tree elements (level-order): ";
    levelOrder(tree);
    std::cout << std::endl;

    // Create a forest
    Forest forest;
    Tree tree1, tree2;
    TreeNode root_node1, root_node2;

    root_node1.data.number = 10;
    root_node1.firstChild = nullptr;
    setTreeRoot(tree1, root_node1);

    TreeNode node11, node12;
    node11.data.number = 11;
    node11.firstChild = nullptr;
    insert(tree1, node11, 0);

    node12.data.number = 12;
    node12.firstChild = nullptr;
    insert(tree1, node12, 0);

    root_node2.data.number = 20;
    root_node2.firstChild = nullptr;
    setTreeRoot(tree2, root_node2);

    TreeNode node21, node22;
    node21.data.number = 21;
    node21.firstChild = nullptr;
    insert(tree2, node21, 0);

    node22.data.number = 22;
    node22.firstChild = nullptr;
    insert(tree2, node22, 0);

    setForestRoot(forest, tree1);
    insert(forest, tree2, 0);

    std::cout << "Forest elements (pre-order): ";
    preOrder(forest, 0);
    std::cout << std::endl;

    std::cout << "Forest elements (post-order): ";
    postOrder(forest, 0);
    std::cout << std::endl;

    std::cout << "Forest elements (level-order): ";
    levelOrder(forest);
    std::cout << std::endl;
}
