//
// 并查集
// 测试
//

#include <iostream>
#include "disjoint_set.h"

using namespace std;
using namespace disjoint_set;

void disjoint_set::test_disjoint_set() {
    DisjointSet set;
    set.size = 10;

    for (int i = 0; i < set.size; ++i) {
        set.nodes[i].data = i;
        set.nodes[i].parent = -1;
    }

    merge(set, 0, 1);
    merge(set, 2, 3);
    merge(set, 4, 5);
    merge(set, 6, 7);
    merge(set, 8, 9);
    merge(set, 1, 3);
    merge(set, 5, 7);
    merge(set, 3, 7);

    cout << "Set after merging: " << endl;
    for (int i = 0; i < set.size; ++i) {
        cout << "Node " << i << " - Parent: " << set.nodes[i].parent << endl;
    }

    cout << "Find operations:" << endl;
    for (int i = 0; i < set.size; ++i) {
        cout << "Find(" << i << ") = " << find(set, i) << endl;
    }
}

