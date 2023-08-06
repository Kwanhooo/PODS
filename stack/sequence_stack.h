//
// 栈 - 顺序栈
// 实现
//

#ifndef STACK_SEQUENCE_STACK_H
#define STACK_SEQUENCE_STACK_H

#define MAX_SIZE 10

#include "element.h"

namespace sequence_stack {

    inline void test_sequence_stack();

    typedef struct SequenceStack {
        Element data[MAX_SIZE];
        int top;
    } Stack;

    // 初始化
    inline void init(Stack &stack) {
        stack.top = -1;
    }

    // 入栈
    inline void push(Stack &stack, Element e) {
        stack.data[++stack.top] = e;
    }

    // 出栈
    inline Element pop(Stack &stack) {
        return stack.data[stack.top--];
    }

    // 判空
    inline bool empty(Stack stack) {
        return stack.top == -1;
    }

    // 判满
    inline bool full(Stack stack) {
        return stack.top == MAX_SIZE - 1;
    }

}
#endif //STACK_SEQUENCE_STACK_H
