//
// KMP算法
// 测试
//

#include <iostream>
#include "sequence_string.h"
#include "kmp.h"

void kmp::test_kmp() {
    sequence_string::String source_str;
    sequence_string::String pattern_str;

    sequence_string::assign(source_str, "aababbaaababaaababaaaababbaa");
    sequence_string::assign(pattern_str, "ababaaababaa");

    std::cout << "源字符串的内容为：";
    sequence_string::print(source_str);

    std::cout << "模式串的内容为：";
    sequence_string::print(pattern_str);

    std::cout << "模式串的 next 数组为：";
    int *next_val = kmp::get_next(pattern_str);
    for (int i = 0; i < pattern_str.length; ++i) {
        std::cout << next_val[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "模式串的优化 next 数组为：";
    kmp::optimize_next(pattern_str, next_val);
    for (int i = 0; i < pattern_str.length; ++i) {
        std::cout << next_val[i] << " ";
    }
    std::cout << std::endl;

    int index = kmp::index(source_str, pattern_str, next_val);
    if (index != -1) {
        std::cout << "模式串在源字符串中的位置是：" << index << std::endl;
    } else {
        std::cout << "模式串未在源字符串中找到。" << std::endl;
    }

    delete[] next_val;
}
