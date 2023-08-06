//
// 栈 - 双向链栈
// 实现
//

#ifndef STACK_DOUBLY_LINKED_STACK_H
#define STACK_DOUBLY_LINKED_STACK_H

#define MAX_SIZE 10

#include "element.h"

namespace doubly_linked_stack {
    inline void test_doubly_linked_stack();

    typedef struct StackNode {
        Element data;
        StackNode *prev;
        StackNode *next;
    } *Node;

    typedef struct DoublyLinkedStack {
        Node head;
        Node tail;
        int size;
    } *Stack;

    inline void init(Stack stack) {
        stack->head = nullptr;
        stack->tail = nullptr;
        stack->size = 0;
    }

    inline bool empty(DoublyLinkedStack stack) {
        return stack.head == nullptr && stack.tail == nullptr;
    }

    inline bool full(DoublyLinkedStack stack) {
        return stack.size == MAX_SIZE;
    }

    inline bool push(Stack stack, Element e) {
        if (full(*stack))
            return false;

        Node new_node = new StackNode;
        new_node->data = e;
        new_node->prev = stack->tail;
        new_node->next = nullptr;
        if (stack->size != 0) {
            stack->tail->next = new_node;
        }
        stack->tail = new_node;
        stack->size++;
        return true;
    }

    inline bool pop(Stack stack, Element &e) {
        if (empty(*stack))
            return false;
        e = stack->tail->data;
        stack->tail = stack->tail->prev;
        stack->size--;
        if (stack->size == 0) {
            stack->head = nullptr;
            stack->tail = nullptr;
        }
    }

    inline void print(DoublyLinkedStack stack) {
        Node p = stack.tail;
        while (p != nullptr) {
            std::cout << p->data.number << " ";
            p = p->prev;
        }
        std::cout << std::endl;
    }
}

#endif //STACK_DOUBLY_LINKED_STACK_H
