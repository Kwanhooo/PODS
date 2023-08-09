//
// 线索二叉树
// 测试
//

#include "threaded_binary_tree.h"

void threaded_binary_tree::test_threaded_binary_tree() {
    Node *root = new Node{Element{5}};
    Node *node1 = new Node{Element{3}};
    Node *node2 = new Node{Element{7}};
    Node *node3 = new Node{Element{2}};
    Node *node4 = new Node{Element{4}};
    Node *node5 = new Node{Element{6}};
    Node *node6 = new Node{Element{8}};

    insert(root, node1, true);
    insert(root, node2, false);
    insert(node1, node3, true);
    insert(node1, node4, false);
    insert(node2, node5, true);
    insert(node2, node6, false);

    Node *pre = nullptr;
    buildInorderThreads(root, pre);

    std::cout << "中序遍历线索二叉树：" << std::endl;
    Node *current = findLeftmostNode(root);
    while (current != nullptr) {
        visit(*current);
        current = getInorderNextNode(current);
    }
    std::cout << std::endl;

    pre = nullptr;
    buildPreorderThreads(root, pre);

    std::cout << "前序遍历线索二叉树：" << std::endl;
    current = root;
    while (current != nullptr) {
        visit(*current);
        current = getPreorderNextNode(current);
    }
    std::cout << std::endl;
}
