//
// 线性表 - 顺序表
// 测试
//

#include "sequence_list.h"
#include <iostream>

int sequence_list::test_sequence_list() {
    SequenceList list;
    init(list);

    std::cout << "插入元素：" << std::endl;
    for (int i = 1; i <= 5; i++) {
        Element e{i};
        insert(list, e, i - 1);
        print(list);
    }

    std::cout << "当前表长：" << length(list) << std::endl;

    std::cout << "按值查找元素：" << std::endl;
    for (int i = 1; i <= 5; i++) {
        Element e{i};
        int pos = locate(list, e);
        if (pos != -1) {
            std::cout << "找到元素 " << i << "，位置为 " << pos << "。" << std::endl;
        } else {
            std::cout << "未找到元素 " << i << "。" << std::endl;
        }
    }

    std::cout << "按位查找元素：" << std::endl;
    for (int i = 0; i < length(list); i++) {
        Element *e = get(list, i);
        if (e != nullptr) {
            std::cout << "位置 " << i << " 的元素为：" << e->number << std::endl;
        } else {
            std::cout << "未找到位置 " << i << " 的元素。" << std::endl;
        }
    }

    std::cout << "删除元素：" << std::endl;
    for (int i = 5; i >= 1; i--) {
        Element *e = remove(list, i - 1);
        if (e != nullptr) {
            std::cout << "删除的元素为：" << e->number << std::endl;
        }
        print(list);
    }

    std::cout << "顺序表是否为空？ " << (empty(list) ? "是" : "否") << std::endl;

    destroy(list);
    std::cout << "顺序表已销毁。" << std::endl;

    return 0;
}

