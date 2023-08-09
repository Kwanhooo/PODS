//
// 二叉树 - 顺序（0起始）
// 实现
//

#ifndef TREE_SEQUENCE_BINARY_TREE_ZERO_H
#define TREE_SEQUENCE_BINARY_TREE_ZERO_H


#define N 128

#include <iostream>
#include "element.h"

namespace sequence_binary_tree_zero {

    inline void test_sequence_binary_tree_zero();

    typedef struct SequenceBinaryTreeNode {
        Element data{-1};
    } TreeNode;

    typedef struct SequenceBinaryTree {
        TreeNode nodes[N];// 第0个存
    } Tree;

    inline int getParentIndex(Tree tree, int self) {
        return self == 1 ? -1 : (self + 1) / 2 - 1;
    }

    inline int getLeftChildIndex(Tree tree, int self) {
        return self * 2 <= N ? self * 2 + 1 : -1;
    }

    inline int getRightChildIndex(Tree tree, int self) {
        return self * 2 + 1 <= N ? self * 2 + 2 : -1;
    }

    inline void setRoot(SequenceBinaryTree &tree, TreeNode node) {
        tree.nodes[0] = node;
    }

    inline bool insert(SequenceBinaryTree &tree, TreeNode node, int parent, bool direction) {
        int targetIndex;
        if (direction) {// 左边
            targetIndex = getLeftChildIndex(tree, parent);
        } else {// 右边
            targetIndex = getRightChildIndex(tree, parent);
        }

        tree.nodes[targetIndex] = node;
        return true;
    }

    inline void visit(TreeNode node) {
        if (node.data.number != -1)
            std::cout << node.data.number << " ";
    }

    // 先序遍历
    inline void PreorderTraverse(Tree tree, int index) {
        if (index < 0 || index > N - 1)
            return;
        visit(tree.nodes[index]);
        PreorderTraverse(tree, getLeftChildIndex(tree, index));
        PreorderTraverse(tree, getRightChildIndex(tree, index));
    }

    inline void InorderTraverse(Tree tree, int index) {
        if (index < 0 || index > N - 1)
            return;
        InorderTraverse(tree, getLeftChildIndex(tree, index));
        visit(tree.nodes[index]);
        InorderTraverse(tree, getRightChildIndex(tree, index));
    }

    inline void PostorderTraverse(Tree tree, int index) {
        if (index < 0 || index > N - 1)
            return;
        PostorderTraverse(tree, getLeftChildIndex(tree, index));
        PostorderTraverse(tree, getRightChildIndex(tree, index));
        visit(tree.nodes[index]);
    }
}


#endif //TREE_SEQUENCE_BINARY_TREE_ZERO_H
