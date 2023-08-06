//
// 队列 - 顺序
// 实现
//

#ifndef QUEUE_SEQUENCE_QUEUE_H
#define QUEUE_SEQUENCE_QUEUE_H

#include <iostream>
#include "element.h"

#define MAX_SIZE 10

namespace sequence_queue {
    inline void test_sequence_queue();

    typedef struct SequenceQueue {
        Element data[MAX_SIZE];
        int front = 0;
        int rear = 0;
    } Queue;

    inline bool empty(SequenceQueue queue) {
        return queue.front == queue.rear;
    }

    inline bool full(SequenceQueue queue) {
        return (queue.rear + 1) % MAX_SIZE == queue.front;
    }

    inline bool enqueue(SequenceQueue &queue, Element e) {
        if (full(queue))
            return false;
        queue.data[queue.rear] = e;
        queue.rear = (queue.rear + 1) % MAX_SIZE;
        return true;
    }

    inline bool dequeue(SequenceQueue &queue, Element &e) {
        if (empty(queue)) {
            return false;
        }
        e = queue.data[queue.front];
        queue.front = (queue.front + 1) % MAX_SIZE;
        return true;
    }

    inline void print(SequenceQueue queue) {
        int p = queue.front;
        while (p != (queue.rear) % MAX_SIZE) {
            std::cout << (queue.data + p)->number << " ";
            p = (p + 1) % MAX_SIZE;
        }
        std::cout << std::endl;
    }

}

#endif //QUEUE_SEQUENCE_QUEUE_H
