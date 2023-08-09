//
// 线索二叉树
// 实现
//

#ifndef TREE_THREADED_BINARY_TREE_H
#define TREE_THREADED_BINARY_TREE_H

#include <iostream>
#include "element.h"

#define COMMON 0
#define THREADED 1

namespace threaded_binary_tree {

    inline void test_threaded_binary_tree();

    typedef struct ThreadedBinaryTreeNode {
        Element data{-1};
        ThreadedBinaryTreeNode *left = nullptr, *right = nullptr;
        int l_tag = COMMON, r_tag = COMMON;
    } Node, *Tree;

    inline void insert(Node *parent, Node *node, bool orientation) {
        if (orientation)
            parent->left = node;
        else
            parent->right = node;
    }

    inline void visit(Node node) {
        std::cout << node.data.number << " ";
    }

    inline Node *findRightmostNode(Node *root) {
        Node *p = root;
        while (p->right != nullptr && p->r_tag == COMMON) {
            p = p->right;
        }
        return p;
    }

    inline Node *findLeftmostNode(Node *root) {
        if (root == nullptr)
            return nullptr;
        Node *p = root;
        while (p->left != nullptr && p->l_tag == COMMON) {
            p = p->left;
        }
        return p;
    }

    inline void buildInorderThreads(Node *node, Node *&pre) {
        if (node == nullptr)
            return;

        buildInorderThreads(node->left, pre);

        if (node->left == nullptr && node->l_tag == COMMON) {
            node->left = pre;
            node->l_tag = THREADED;
        }

        if (pre != nullptr && pre->right == nullptr && pre->r_tag == COMMON) {
            pre->right = node;
            pre->r_tag = THREADED;
        }

        pre = node;

        buildInorderThreads(node->right, pre);
    }

    inline Node *getInorderPreNode(Node *current) {
        if (current == nullptr)
            return nullptr;

        if (current->l_tag == THREADED)
            return current->left;

        return findRightmostNode(current->left);
    }

    inline Node *getInorderNextNode(Node *current) {
        if (current == nullptr)
            return nullptr;

        if (current->r_tag == THREADED)
            return current->right;

        return findLeftmostNode(current->right);
    }

    inline void buildPreorderThreads(Node *node, Node *&pre) {
        if (node == nullptr)
            return;

        visit(*node);

        if (node->left == nullptr && node->l_tag == COMMON) {
            node->left = pre;
            node->l_tag = THREADED;
        }

        if (pre != nullptr && pre->right == nullptr && pre->r_tag == COMMON) {
            pre->right = node;
            pre->r_tag = THREADED;
        }

        if (pre != nullptr && pre->r_tag == THREADED) {
            pre->right = node;
        }

        pre = node;

        if (node->l_tag == COMMON)
            buildPreorderThreads(node->left, pre);

        if (node->r_tag == COMMON)
            buildPreorderThreads(node->right, pre);
    }

    inline Node *getPreorderNextNode(Node *current) {
        if (current == nullptr)
            return nullptr;

        if (current->left != nullptr)
            return current->left;
        return current->right;
    }

    inline void buildPostorderThreads(Node *node, Node *&pre) {
        if (node == nullptr)
            return;

        if (node->l_tag == COMMON)
            buildPostorderThreads(node->left, pre);

        if (node->r_tag == COMMON)
            buildPostorderThreads(node->right, pre);

        if (node->left == nullptr && node->l_tag == COMMON) {
            node->left = pre;
            node->l_tag = THREADED;
        }

        if (pre != nullptr && pre->right == nullptr && pre->r_tag == COMMON) {
            pre->right = node;
            pre->r_tag = THREADED;
        }

        pre = node;
    }

}

#endif //TREE_THREADED_BINARY_TREE_H