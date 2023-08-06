//
// 栈 - 链栈
// 测试
//

#include <iostream>
#include "linked_stack.h"

void linked_stack::test_linked_stack() {
    Node head = new StackNode;
    head->next = nullptr;

    std::cout << "链栈是否为空？ " << (empty(head) ? "是" : "否") << std::endl;

    std::cout << "向链栈中压入元素：" << std::endl;
    for (int i = 1; i <= 5; i++) {
        Element e{i};
        push(head, e);
        std::cout << "压入元素：" << e.number << std::endl;
        print(head);
    }

    std::cout << "链栈是否为空？ " << (empty(head) ? "是" : "否") << std::endl;

    std::cout << "从链栈中弹出元素：" << std::endl;
    Element e;
    while (!empty(head)) {
        pop(head, e);
        std::cout << "弹出元素：" << e.number << std::endl;
        print(head);
    }

    std::cout << "链栈是否为空？ " << (empty(head) ? "是" : "否") << std::endl;

    delete head;
}


