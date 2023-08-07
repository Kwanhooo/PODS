//
// KMP算法
// 实现
//

#ifndef STRING_KMP_H
#define STRING_KMP_H


#include "sequence_string.h"

namespace kmp {

    inline void test_kmp();

    inline int *get_next(sequence_string::String pattern) {
        int *next = new int[pattern.length];
        next[0] = -1;

        int i = 1, j = 0;
        while (i < pattern.length) {
            if (j == -1 || pattern.data[i] == pattern.data[j]) {
                i++;
                j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }

        return next;
    }

    inline void *optimize_next(sequence_string::String pattern, int *next) {
        for (int i = 0; i < pattern.length; ++i) {
            int next_val = next[i];
            if (pattern.data[i] == pattern.data[next_val]) {
                next[i] = next[next_val];
            }
        }
    }

    inline int index(sequence_string::String source, sequence_string::String pattern, const int *next_val) {
        int i = 0, j = 0;
        while (i < source.length && j < pattern.length) {
            if (j == -1 || source.data[i] == pattern.data[j]) {
                i++, j++;
            } else {
                j = next_val[j];
            }
        }
        if (j >= pattern.length) {
            return i - pattern.length;
        }
        return -1;
    }

}

#endif //STRING_KMP_H
