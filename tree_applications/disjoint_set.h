//
// 并查集
// 实现
//

#ifndef TREE_APPLICATIONS_DISJOINT_SET_H
#define TREE_APPLICATIONS_DISJOINT_SET_H

#define MAX_SIZE 100

namespace disjoint_set {

    inline void test_disjoint_set();

    struct Node {
        int data;
        int parent;
    };

    typedef struct DisjointSet {
        Node nodes[MAX_SIZE];
        int size;
    } Set;

    inline int find(DisjointSet set, int self) {
        if (set.nodes[self].parent == -1)
            return self;
        return find(set, set.nodes[self].parent);
    }

    inline int get_depth(DisjointSet set, int root) {
        int max_depth = 1;
        // 找到root的所有孩子
        for (int i = 0; i < set.size; ++i) {
            if (set.nodes[i].parent == root) {
                int tmp = get_depth(set, i);
                if (tmp > max_depth)
                    max_depth = tmp;
            }
        }
        return max_depth;
    }

    inline void merge(DisjointSet &set, int a, int b) {
        // 找到根节点
        int a_root = find(set, a);
        int b_root = find(set, b);

        if (a_root == b_root) {
            return; // 已经在同一个集合中
        }

        // 求出树高
        int a_depth = get_depth(set, a_root);
        int b_depth = get_depth(set, b_root);

        // 如果a高于b，则将b附到a
        if (a_depth > b_depth) {
            set.nodes[b_root].parent = a_root;
        } else {
            set.nodes[a_root].parent = b_root;
        }
    }

}

#endif //TREE_APPLICATIONS_DISJOINT_SET_H
