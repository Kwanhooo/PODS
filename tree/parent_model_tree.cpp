//
// 树(森林)的双亲表示法
// 测试
//

#include <iostream>
#include "parent_model_tree.h"

void parent_model_tree::test_parent_model_tree() {
    // Create a tree
    Tree tree;
    Node root_node;
    root_node.data.number = 1;
    setTreeRoot(tree, root_node);

    treeInsert(tree, Element{2}, 0);
    treeInsert(tree, Element{3}, 0);
    treeInsert(tree, Element{4}, 1);
    treeInsert(tree, Element{5}, 1);
    treeInsert(tree, Element{6}, 2);

    std::cout << "Tree elements (pre-order): ";
    preOrderTraverse(tree, 0);
    std::cout << std::endl;

    std::cout << "Tree elements (post-order): ";
    postOrderTraverse(tree, 0);
    std::cout << std::endl;

    std::cout << "Tree elements (level-order): ";
    levelOrderTraverse(tree);
    std::cout << std::endl;

    // Create a forest
    Forest forest;
    Tree tree1, tree2;
    Node root_node1, root_node2;

    root_node1.data.number = 10;
    setTreeRoot(tree1, root_node1);
    treeInsert(tree1, Element{11}, 0);
    treeInsert(tree1, Element{12}, 0);

    root_node2.data.number = 20;
    setTreeRoot(tree2, root_node2);
    treeInsert(tree2, Element{21}, 0);
    treeInsert(tree2, Element{22}, 0);

    setRootForest(forest, tree);
    forestInsert(forest, tree1, 0);
    forestInsert(forest, tree2, 0);

    std::cout << "Forest elements (pre-order): ";
    preOrderTraverseForest(forest, 0);
    std::cout << std::endl;

    std::cout << "Forest elements (post-order): ";
    postOrderTraverseForest(forest, 0);
    std::cout << std::endl;

    std::cout << "Forest elements (level-order): ";
    levelOrderTraverseForest(forest);
    std::cout << std::endl;
}
