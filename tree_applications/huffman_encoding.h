//
// Huffman编码
// 测试
//

#ifndef TREE_APPLICATIONS_HUFFMAN_ENCODING_H
#define TREE_APPLICATIONS_HUFFMAN_ENCODING_H

#include <cstdio>
#include <cstdlib>

#define NUM_CHARS 26

namespace huffman_encoding {

    void test_huffman_encoding();

    struct HuffmanNode {
        char data;
        int frequency;
        struct HuffmanNode *left;
        struct HuffmanNode *right;
    };

    typedef struct HuffmanNode HuffmanNode;

    struct MinHeap {
        int size;
        HuffmanNode **array;
    };

    typedef struct MinHeap MinHeap;

    inline HuffmanNode *create_node(char data, int frequency) {
        auto *node = (HuffmanNode *) malloc(sizeof(HuffmanNode));
        node->data = data;
        node->frequency = frequency;
        node->left = node->right = nullptr;
        return node;
    }

    inline MinHeap *create_min_heap(int capacity) {
        auto *min_heap = (MinHeap *) malloc(sizeof(MinHeap));
        min_heap->size = 0;
        min_heap->array = (HuffmanNode **) malloc(capacity * sizeof(HuffmanNode *));
        return min_heap;
    }

    inline void swap_nodes(HuffmanNode **a, HuffmanNode **b) {
        HuffmanNode *temp = *a;
        *a = *b;
        *b = temp;
    }

    inline void min_heapify(MinHeap *min_heap, int idx) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < min_heap->size && min_heap->array[left]->frequency < min_heap->array[smallest]->frequency)
            smallest = left;
        if (right < min_heap->size && min_heap->array[right]->frequency < min_heap->array[smallest]->frequency)
            smallest = right;

        if (smallest != idx) {
            swap_nodes(&min_heap->array[idx], &min_heap->array[smallest]);
            min_heapify(min_heap, smallest);
        }
    }

    inline int is_size_one(MinHeap *min_heap) {
        return (min_heap->size == 1);
    }

    inline HuffmanNode *extract_min(MinHeap *min_heap) {
        HuffmanNode *temp = min_heap->array[0];
        min_heap->array[0] = min_heap->array[min_heap->size - 1];
        --min_heap->size;
        min_heapify(min_heap, 0);
        return temp;
    }

    inline void insert_min_heap(MinHeap *min_heap, HuffmanNode *node) {
        ++min_heap->size;
        int i = min_heap->size - 1;
        while (i && node->frequency < min_heap->array[(i - 1) / 2]->frequency) {
            min_heap->array[i] = min_heap->array[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        min_heap->array[i] = node;
    }

    inline MinHeap *build_min_heap(char data[], int frequency[], int size) {
        MinHeap *min_heap = create_min_heap(size);
        for (int i = 0; i < size; ++i)
            min_heap->array[i] = create_node(data[i], frequency[i]);
        min_heap->size = size;

        int n = min_heap->size - 1;
        for (int i = (n - 1) / 2; i >= 0; --i)
            min_heapify(min_heap, i);

        return min_heap;
    }

    inline HuffmanNode *build_huffman_tree(char data[], int frequency[], int size) {
        HuffmanNode *left, *right, *top;

        MinHeap *min_heap = build_min_heap(data, frequency, size);

        while (!is_size_one(min_heap)) {
            left = extract_min(min_heap);
            right = extract_min(min_heap);

            top = create_node('$', left->frequency + right->frequency);
            top->left = left;
            top->right = right;

            insert_min_heap(min_heap, top);
        }

        return extract_min(min_heap);
    }

    inline void print_codes(HuffmanNode *root, int arr[], int top) {
        if (root->left) {
            arr[top] = 0;
            print_codes(root->left, arr, top + 1);
        }

        if (root->right) {
            arr[top] = 1;
            print_codes(root->right, arr, top + 1);
        }

        if (root->left == nullptr && root->right == nullptr) {
            printf("Character: %c, Huffman Code: ", root->data);
            for (int i = 0; i < top; ++i)
                printf("%d", arr[i]);
            printf("\n");
        }
    }

    inline void huffman_encoding(char data[], int frequency[], int size) {
        HuffmanNode *root = build_huffman_tree(data, frequency, size);
        int arr[100], top = 0;
        printf("Huffman Codes:\n");
        print_codes(root, arr, top);
    }
}

#endif //TREE_APPLICATIONS_HUFFMAN_ENCODING_H
