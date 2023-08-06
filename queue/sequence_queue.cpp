//
// 队列 - 顺序
// 测试
//

#include <iostream>
#include "sequence_queue.h"

void sequence_queue::test_sequence_queue() {
    Queue queue;

    std::cout << "顺序队列是否为空？ " << (empty(queue) ? "是" : "否") << std::endl;

    std::cout << "向顺序队列中插入元素：" << std::endl;
    for (int i = 1; i <= 5; i++) {
        Element e{i};
        if (enqueue(queue, e)) {
            std::cout << "插入元素：" << e.number << std::endl;
            print(queue);
        } else {
            std::cout << "顺序队列已满，无法插入元素：" << e.number << std::endl;
        }
    }

    std::cout << "顺序队列是否为空？ " << (empty(queue) ? "是" : "否") << std::endl;
    std::cout << "顺序队列是否已满？ " << (full(queue) ? "是" : "否") << std::endl;

    std::cout << "从顺序队列中取出元素：" << std::endl;
    Element e;
    while (dequeue(queue, e)) {
        std::cout << "取出元素：" << e.number << std::endl;
        print(queue);
    }

    std::cout << "顺序队列是否为空？ " << (empty(queue) ? "是" : "否") << std::endl;
}


