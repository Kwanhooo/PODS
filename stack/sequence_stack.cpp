//
// 栈 - 顺序栈
// 测试
//

#include <iostream>
#include "sequence_stack.h"

void sequence_stack::test_sequence_stack() {
    Stack stack;
    init(stack);

    std::cout << "栈是否为空？ " << (empty(stack) ? "是" : "否") << std::endl;

    std::cout << "向栈中压入元素：" << std::endl;
    for (int i = 1; i <= 5; i++) {
        Element e{i};
        if (!full(stack)) {
            push(stack, e);
            std::cout << "压入元素: " << e.number << std::endl;
        } else {
            std::cout << "栈已满，无法压入元素: " << e.number << std::endl;
        }
    }

    std::cout << "栈是否为空？ " << (empty(stack) ? "是" : "否") << std::endl;
    std::cout << "栈是否已满？ " << (full(stack) ? "是" : "否") << std::endl;

    std::cout << "从栈中弹出元素：" << std::endl;
    while (!empty(stack)) {
        Element e = pop(stack);
        std::cout << "弹出元素: " << e.number << std::endl;
    }

    std::cout << "栈是否为空？ " << (empty(stack) ? "是" : "否") << std::endl;
}

