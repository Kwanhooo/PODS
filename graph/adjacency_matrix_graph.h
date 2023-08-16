//
// 邻接矩阵
// 实现
//

#ifndef GRAPH_ADJACENCY_MATRIX_GRAPH_H
#define GRAPH_ADJACENCY_MATRIX_GRAPH_H

namespace adjacency_matrix {
    inline void test_adjacency_matrix();

    typedef struct AdjacencyMatrixGraph {
        int matrix[100][100];
        int vertex_num;
    } Graph;

    void init_graph(Graph *graph, int vertex_num) {
        graph->vertex_num = vertex_num;
        for (int i = 0; i < vertex_num; ++i) {
            for (int j = 0; j < vertex_num; ++j) {
                graph->matrix[i][j] = 0;
            }
        }
    }

    void add_edge(Graph *graph, int i, int j) {
        graph->matrix[i][j] = 1;
        graph->matrix[j][i] = 1;
    }
}

#endif //GRAPH_ADJACENCY_MATRIX_GRAPH_H
