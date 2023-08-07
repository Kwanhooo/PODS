//
// 串 - 顺序
// 实现
//

#ifndef STRING_SEQUENCE_STRING_H
#define STRING_SEQUENCE_STRING_H

#include <iostream>

#define MAX_LENGTH 255

namespace sequence_string {

    inline void test_sequence_string();

    typedef struct SequenceString {
        char data[MAX_LENGTH];
        int length;
    } String;

    inline void assign(String &str, const char *chars) {
        int i = 0;
        while (chars[i] != '\0') {
            str.data[i] = chars[i];
            i++;
        }
        str.length = i;
    }

    inline void copy(String &dest, String src) {
        for (int i = 0; i < src.length; i++) {
            dest.data[i] = src.data[i];
        }
        dest.length = src.length;
    }

    inline bool empty(String str) {
        return str.length == 0;
    }

    inline bool compare(String str_a, String str_b) {
        for (int i = 0; i < str_a.length && i < str_b.length; i++) {
            if (str_a.data[i] != str_b.data[i]) {
                return str_a.data[i] - str_b.data[i];
            }
        }
        return str_a.length - str_b.length;
    }

    inline int length(String str) {
        return str.length;
    }

    inline void substring(String &sub, String src, int pos, int length) {
        for (int i = 0; i < length; i++) {
            sub.data[i] = src.data[pos + i];
        }
        sub.length = length;
    }

    inline void concat(String &result, String str_a, String str_b) {
        for (int i = 0; i < str_a.length; i++) {
            result.data[i] = str_a.data[i];
        }
        for (int i = 0; i < str_b.length; i++) {
            result.data[str_a.length + i] = str_b.data[i];
        }
        result.length = str_a.length + str_b.length;
    }

    inline int index(String str, String pattern) {
        for (int src = 0; src < str.length - pattern.length + 1; ++src) {
            int cursor = 0;
            bool found = true;
            while (cursor < pattern.length) {
                if (str.data[src + cursor] != pattern.data[cursor]) {
                    found = false;
                    break;
                }
                cursor++;
            }
            if (found)
                return src;
        }
        return -1;
    }

    inline void clear(String &target) {
        target.length = 0;
    }

    inline void destroy(String &target) {
        // 此方法仅在堆分配的实现下需要
    }

    inline void print(String str) {
        for (int i = 0; i < str.length; ++i) {
            std::cout << str.data[i] << " ";
        }
        std::cout << std::endl;
    }

}

#endif //STRING_SEQUENCE_STRING_H
