//
// 树(森林)的双亲表示法
// 实现
//

#ifndef TREE_PARENT_MODEL_TREE_H
#define TREE_PARENT_MODEL_TREE_H

#define PARENT_TREE_MAX_SIZE 100
#define PARENT_FOREST_MAX_SIZE 100

#include <iostream>
#include "element.h"

namespace parent_model_tree {

    inline void test_parent_model_tree();

    typedef struct ParentModelTreeNode {
        Element data{-1};
        int parent = -1;
    } Node;

    typedef struct ParentModelTree {
        Node nodes[PARENT_TREE_MAX_SIZE];
        int count = 0;
        int parent = -1;
    } Tree;

    typedef struct ParentModelForest {
        Tree trees[PARENT_FOREST_MAX_SIZE];
        int count = 0;
    } Forest;

    inline void setTreeRoot(Tree &tree, Node node) {
        tree.nodes[0] = node;
        tree.count = 1;
    }

    inline void treeInsert(Tree &tree, Element e, int parent) {
        Node new_node = Node{};
        new_node.data = e;
        new_node.parent = parent;
        tree.nodes[tree.count] = new_node;
        tree.count++;
    }

    inline void visitTreeNode(Tree tree, int pos) {
        std::cout << tree.nodes[pos].data.number << " ";
    }

    inline void setRootForest(Forest &forest, Tree tree) {
        forest.trees[0] = tree;
        forest.count = 1;
    }

    inline void forestInsert(Forest &forest, Tree &tree, int parent) {
        forest.trees[forest.count] = tree;
        forest.trees[forest.count].parent = parent;
        forest.count++;
    }

    // 树的先根遍历
    inline void preOrderTraverse(Tree tree, int pos) {
        visitTreeNode(tree, pos);
        for (int i = 0; i < tree.count; ++i) {
            if (tree.nodes[i].parent == pos) {
                preOrderTraverse(tree, i);
            }
        }
    }

    // 树的后根遍历
    inline void postOrderTraverse(Tree tree, int pos) {
        for (int i = 0; i < tree.count; ++i) {
            if (tree.nodes[i].parent == pos) {
                postOrderTraverse(tree, i);
            }
        }
        visitTreeNode(tree, pos);
    }

    // 树的层次遍历
    inline void levelOrderTraverse(Tree tree) {
        for (int i = 0; i < tree.count; ++i) {
            visitTreeNode(tree, i);
        }
    }

    inline void visitForestNode(Forest forest, int pos) {
        std::cout << "Tree " << pos << ": ";
        preOrderTraverse(forest.trees[pos], 0);
    }

    // 森林的先根遍历
    inline void preOrderTraverseForest(Forest forest, int pos) {
        std::cout << std::endl;
        visitForestNode(forest, pos);
        for (int i = 0; i < forest.count; ++i) {
            if (forest.trees[i].parent == pos) {
                preOrderTraverseForest(forest, i);
            }
        }
    }

    // 森林的后根遍历
    inline void postOrderTraverseForest(Forest forest, int pos) {
        for (int i = 0; i < forest.count; ++i) {
            if (forest.trees[i].parent == pos) {
                postOrderTraverseForest(forest, i);
            }
        }
        std::cout << std::endl;
        visitForestNode(forest, pos);
    }

    // 森林的层次遍历
    inline void levelOrderTraverseForest(Forest forest) {
        for (int i = 0; i < forest.count; ++i) {
            std::cout << std::endl;
            visitForestNode(forest, i);
        }
    }
}

#endif //TREE_PARENT_MODEL_TREE_H
