//
// Huffman编码
// 实现
//

#include "huffman_encoding.h"

inline void huffman_encoding::test_huffman_encoding() {
    char characters[NUM_CHARS] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                                  'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int frequencies[NUM_CHARS] = {10, 15, 12, 3, 4, 13, 1, 9, 5, 6, 22, 18, 4, 8, 7, 11, 9, 8, 9, 12, 6, 16, 3, 5, 19,
                                  14};

    huffman_encoding(characters, frequencies, NUM_CHARS);
}
