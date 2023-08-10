//
// 孩子兄弟表示法
// 实现
//

#ifndef TREE_SIBLING_MODEL_TREE_H
#define TREE_SIBLING_MODEL_TREE_H

#include "element.h"
#include "child_model_tree.h"

namespace sibling_model_tree {

    inline void test_sibling_model_tree();

    typedef struct TreeNode {
        Element data;
        struct TreeNode *first_child, *next_sibling;
    } TreeNode, *Tree;

}

#endif //TREE_SIBLING_MODEL_TREE_H
