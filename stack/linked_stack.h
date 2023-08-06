//
// 栈 - 链栈
// 实现
//

#ifndef STACK_LINKED_STACK_H
#define STACK_LINKED_STACK_H

#include <iostream>
#include "element.h"

namespace linked_stack {
    inline void test_linked_stack();

    typedef struct StackNode {
        Element data;
        StackNode *next;
    } *Node;

    inline void push(Node head, Element e) {
        Node node = new StackNode;
        node->data = e;
        node->next = head->next;
        head->next = node;
    }

    inline bool empty(Node head) {
        return head->next == nullptr;
    }

    inline void pop(Node head, Element &e) {
        if (empty(head)) {
            return;
        }
        e = head->next->data;
        head->next = head->next->next;
    }

    inline void print(Node head) {
        Node p = head->next;
        while (p != nullptr) {
            std::cout << p->data.number << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
}

#endif //STACK_LINKED_STACK_H
