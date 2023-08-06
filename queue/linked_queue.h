//
// 队列 - 链
// 实现
//

#ifndef QUEUE_LINKED_QUEUE_H
#define QUEUE_LINKED_QUEUE_H

#define MAX_SIZE 5

#include <iostream>
#include "element.h"

namespace linked_queue {
    inline void test_linked_queue();

    typedef struct QueueNode {
        Element data{};
        QueueNode *next = nullptr;
    } *Node;

    inline bool empty(Node head) {
        return head->next == nullptr;
    }

    inline bool full(Node head) {
        int count = 0;
        Node p = head->next;
        while (p != nullptr) {
            count++;
            p = p->next;
        }
        return count == MAX_SIZE;
    }

    inline bool enqueue(Node head, Element e) {
        if (full(head))
            return false;

        Node p = head;
        while (p->next != nullptr) {
            p = p->next;
        }

        Node new_node = new QueueNode{e, nullptr};
        p->next = new_node;

        return true;
    }

    inline bool dequeue(Node head, Element &e) {
        if (empty(head))
            return false;

        e = head->next->data;
        head->next = head->next->next;

        return true;
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

#endif //QUEUE_LINKED_QUEUE_H
