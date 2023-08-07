//
// 串 - 顺序
// 测试
//

#include <iostream>
#include "sequence_string.h"

void sequence_string::test_sequence_string() {
    String str_a;
    assign(str_a, "Hello");

    String str_b;
    assign(str_b, "World");

    std::cout << "字符串 str_a 的内容为：";
    print(str_a);

    std::cout << "字符串 str_b 的内容为：";
    print(str_b);

    std::cout << "字符串 str_a 的长度为：" << length(str_a) << std::endl;
    std::cout << "字符串 str_b 的长度为：" << length(str_b) << std::endl;

    std::cout << "字符串 str_a 是否为空？ " << (empty(str_a) ? "是" : "否") << std::endl;
    std::cout << "字符串 str_b 是否为空？ " << (empty(str_b) ? "是" : "否") << std::endl;

    String str_c;
    concat(str_c, str_a, str_b);
    std::cout << "字符串 str_c 连接 str_a 和 str_b 后的内容为：";
    print(str_c);

    String sub_str;
    substring(sub_str, str_c, 2, 5);
    std::cout << "从字符串 str_c 中提取子串，内容为：";
    print(sub_str);

    String pattern;
    assign(pattern, "lo");
    int i = index(str_c, pattern);
    if (i != -1) {
        std::cout << "子串 pattern 在 str_c 中的位置是：" << i << std::endl;
    } else {
        std::cout << "子串 pattern 未在 str_c 中找到。" << std::endl;
    }

    String str_d;
    copy(str_d, str_a);
    std::cout << "复制 str_a 到 str_d 后的内容为：";
    print(str_d);

    std::cout << "比较 str_a 和 str_b 的结果是：" << compare(str_a, str_b) << std::endl;

    clear(str_a);
    std::cout << "清空 str_a 后的内容为：";
    print(str_a);
}

