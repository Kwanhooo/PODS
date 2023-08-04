//
// 线性表 - 链表
// 测试
//

#include <iostream>
#include "linked_list.h"

#include <iostream>
#include "linked_list.h"

int linked_list::test_linked_list() {
    LinkedList list;
    init(list);

    std::cout << "使用 insert_head 插入元素：" << std::endl;
    for (int i = 5; i >= 1; i--) {
        insert_head(list, Element{i});
        print(list);
    }

    std::cout << "使用 insert_tail 插入元素：" << std::endl;
    for (int i = 6; i <= 10; i++) {
        insert_tail(list, Element{i});
        print(list);
    }

    std::cout << "链表的长度为：" << length(list) << std::endl;

    std::cout << "按值查找元素：" << std::endl;
    for (int i = 1; i <= 10; i++) {
        Node *node = find_by_value(list, Element{i});
        if (node != nullptr) {
            std::cout << "找到元素 " << i << "。" << std::endl;
        } else {
            std::cout << "未找到元素 " << i << "。" << std::endl;
        }
    }

    std::cout << "按序号查找元素：" << std::endl;
    for (int i = 0; i < length(list); i++) {
        Node *node = find_by_index(list, i);
        if (node != nullptr) {
            std::cout << "索引 " << i << " 处的元素为：" << node->data.number << std::endl;
        } else {
            std::cout << "未找到索引 " << i << " 处的元素。" << std::endl;
        }
    }

    std::cout << "删除元素：" << std::endl;
    for (int i = 1; i <= 10; i++) {
        remove(list, Element{i});
        print(list);
    }

    std::cout << "链表是否为空？ " << (is_empty(list) ? "是" : "否") << std::endl;

    destroy(list);
    std::cout << "链表已销毁。" << std::endl;

    return 0;
}
