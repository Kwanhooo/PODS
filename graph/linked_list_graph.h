//
// 邻接表
// 实现
//

#ifndef GRAPH_LINKED_LIST_GRAPH_H
#define GRAPH_LINKED_LIST_GRAPH_H

namespace linked_list_graph {
    
    inline void test_linked_list_graph();

    typedef struct LinkedListGraphVertex {
        int data;
        struct LinkedListGraphVertex *first_edge, *next_vertex;
    } Vertex;

    typedef struct LinkedListGraph {
        Vertex vertexes[1000];
        int vertex_num;
    } Graph;
}

#endif //GRAPH_LINKED_LIST_GRAPH_H
