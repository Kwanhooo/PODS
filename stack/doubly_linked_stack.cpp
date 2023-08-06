//
// 栈 - 双向链栈
// 测试
//

#include <iostream>
#include "doubly_linked_stack.h"

void doubly_linked_stack::test_doubly_linked_stack() {
    DoublyLinkedStack stack;
    init(&stack);

    std::cout << "双向链栈是否为空？ " << (empty(stack) ? "是" : "否") << std::endl;

    std::cout << "向双向链栈中压入元素：" << std::endl;
    for (int i = 1; i <= 5; i++) {
        Element e{i};
        if (push(&stack, e)) {
            std::cout << "压入元素：" << e.number << std::endl;
            print(stack);
        } else {
            std::cout << "双向链栈已满，无法压入元素：" << e.number << std::endl;
        }
    }

    std::cout << "双向链栈是否为空？ " << (empty(stack) ? "是" : "否") << std::endl;

    std::cout << "从双向链栈中弹出元素：" << std::endl;
    Element e;
    while (pop(&stack, e)) {
        std::cout << "弹出元素：" << e.number << std::endl;
        print(stack);
    }

    std::cout << "双向链栈是否为空？ " << (empty(stack) ? "是" : "否") << std::endl;
}


