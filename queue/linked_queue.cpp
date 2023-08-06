//
// 队列 - 链
// 测试
//

#include <iostream>
#include "linked_queue.h"

void linked_queue::test_linked_queue() {
    Node head = new QueueNode;
    head->next = nullptr;

    std::cout << "链式队列是否为空？ " << (empty(head) ? "是" : "否") << std::endl;

    std::cout << "向链式队列中插入元素：" << std::endl;
    for (int i = 1; i <= 5; i++) {
        Element e{i};
        if (enqueue(head, e)) {
            std::cout << "插入元素：" << e.number << std::endl;
            print(head);
        } else {
            std::cout << "链式队列已满，无法插入元素：" << e.number << std::endl;
        }
    }

    std::cout << "链式队列是否为空？ " << (empty(head) ? "是" : "否") << std::endl;
    std::cout << "链式队列是否已满？ " << (full(head) ? "是" : "否") << std::endl;

    std::cout << "从链式队列中取出元素：" << std::endl;
    Element e;
    while (dequeue(head, e)) {
        std::cout << "取出元素：" << e.number << std::endl;
        print(head);
    }

    std::cout << "链式队列是否为空？ " << (empty(head) ? "是" : "否") << std::endl;

    delete head;
}