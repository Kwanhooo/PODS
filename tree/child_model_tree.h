//
// 树(森林)的孩子表示法
// 实现
//

#ifndef TREE_CHILD_MODEL_TREE_H
#define TREE_CHILD_MODEL_TREE_H

#define CHILD_MODEL_MAX_SIZE 100

#include <iostream>
#include "element.h"

namespace child_model_tree {

    inline void test_child_model_tree();

    struct Child {
        int index;
        Child *next;
    };

    typedef struct ChildModelTreeNode {
        Element data;
        Child *firstChild;
    } TreeNode;

    typedef struct ChildModelTree {
        TreeNode nodes[CHILD_MODEL_MAX_SIZE];
        int count;
    } Tree;

    typedef struct ChildModelForest {
        Tree trees[CHILD_MODEL_MAX_SIZE];
        int count;
    } Forest;

    inline void setTreeRoot(Tree &tree, TreeNode node) {
        tree.nodes[0] = node;
        tree.count++;
    }

    inline void insert(Tree &tree, TreeNode node, int parent) {
        // 先插入自己
        tree.nodes[tree.count] = node;
        tree.count++;

        // 再插入父亲的孩子链表
        Child *child = new Child;
        child->index = tree.count;
        child->next = nullptr;

        if (tree.nodes[parent].firstChild == nullptr) {
            tree.nodes[parent].firstChild = child;
        } else {
            Child *p = tree.nodes[parent].firstChild;
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = child;
        }
    }

    inline void setForestRoot(Forest &forest, Tree tree) {
        forest.trees[0] = tree;
        forest.count++;
    }

    inline void insert(Forest &forest, Tree tree, int parentTree) {
        // 先插入自己
        forest.trees[forest.count] = tree;
        forest.count++;

        // 再插入父亲的孩子链表
        Child *child = new Child;
        child->index = forest.count;
        child->next = nullptr;

        if (forest.trees[parentTree].nodes[0].firstChild == nullptr) {
            forest.trees[parentTree].nodes[0].firstChild = child;
        } else {
            Child *p = forest.trees[parentTree].nodes[0].firstChild;
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = child;
        }
    }

    // 树的先根遍历
    inline void preOrder(Tree tree, int index) {
        std::cout << tree.nodes[index].data.number << " ";
        Child *p = tree.nodes[index].firstChild;
        while (p != nullptr) {
            preOrder(tree, p->index);
            p = p->next;
        }
    }

    // 树的后根遍历
    inline void postOrder(Tree tree, int index) {
        Child *p = tree.nodes[index].firstChild;
        while (p != nullptr) {
            postOrder(tree, p->index);
            p = p->next;
        }
        std::cout << tree.nodes[index].data.number << " ";
    }

    // 树的层次遍历
    inline void levelOrder(Tree tree) {
        Child *queue[CHILD_MODEL_MAX_SIZE];
        int front = 0, rear = 0;

        Child *p = tree.nodes[0].firstChild;
        while (p != nullptr) {
            queue[rear++] = p;
            p = p->next;
        }

        while (front != rear) {
            Child *q = queue[front++];
            std::cout << tree.nodes[q->index].data.number << " ";

            Child *p = tree.nodes[q->index].firstChild;
            while (p != nullptr) {
                queue[rear++] = p;
                p = p->next;
            }
        }
    }

    // 森林的先根遍历
    inline void preOrder(Forest forest, int index) {
        std::cout << forest.trees[index].nodes[0].data.number << " ";
        Child *p = forest.trees[index].nodes[0].firstChild;
        while (p != nullptr) {
            preOrder(forest, p->index);
            p = p->next;
        }
    }

    // 森林的后根遍历
    inline void postOrder(Forest forest, int index) {
        Child *p = forest.trees[index].nodes[0].firstChild;
        while (p != nullptr) {
            postOrder(forest, p->index);
            p = p->next;
        }
        std::cout << forest.trees[index].nodes[0].data.number << " ";
    }

    // 森林的层次遍历
    inline void levelOrder(Forest forest) {
        Child *queue[CHILD_MODEL_MAX_SIZE];
        int front = 0, rear = 0;

        Child *p = forest.trees[0].nodes[0].firstChild;
        while (p != nullptr) {
            queue[rear++] = p;
            p = p->next;
        }

        while (front != rear) {
            Child *q = queue[front++];
            std::cout << forest.trees[q->index].nodes[0].data.number << " ";

            Child *p = forest.trees[q->index].nodes[0].firstChild;
            while (p != nullptr) {
                queue[rear++] = p;
                p = p->next;
            }
        }
    }

}

#endif //TREE_CHILD_MODEL_TREE_H
