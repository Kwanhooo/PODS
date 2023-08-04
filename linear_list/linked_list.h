//
// 线性表 - 链表
// 实现
//

#ifndef LINEAR_LIST_LINKED_LIST_H
#define LINEAR_LIST_LINKED_LIST_H

#include "element.h"

namespace linked_list {
    // 测试函数
    inline int test_linked_list();

    /**
     * 1. 数据结构定义
     */

    // 单链表节点
    typedef struct Node {
        Element data;
        Node *next;
    } Node, *LinkedList;

    /**
     * 2. 基本操作
     */

    // 初始化
    inline void init(LinkedList &list) {
        list = new Node;
    }

    // 求表长
    inline int length(LinkedList list) {
        int len = 0;
        Node *p = list;
        while (p->next != nullptr) {
            p = p->next;
            len++;
        }
        return len;
    }

    // 按值查找
    inline Node *find_by_value(LinkedList &head, Element e) {
        Node *p = head;
        while (p->next != nullptr && p->data != e) {
            p = p->next;
        }
        if (p->data == e) {
            return p;
        } else {
            return nullptr;
        }
    }

    // 按序号查找
    inline Node *find_by_index(LinkedList &head, int index) {
        Node *p = head;
        int i = 0;
        while (p->next != nullptr && i < index) {
            p = p->next;
            i++;
        }
        if (i == index) {
            return p;
        } else {
            return nullptr;
        }
    }

    // 头插法
    inline void insert_head(LinkedList &head, Element e) {
        Node *node = new Node;
        node->data = e;
        node->next = head->next;
        head->next = node;
    }

    // 尾插法
    inline void insert_tail(LinkedList &head, Element e) {
        Node *node = new Node;
        node->data = e;
        node->next = nullptr;
        Node *p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = node;
    }

    // 删除
    inline void remove(LinkedList &head, Element e) {
        Node *p = head;
        while (p->next != nullptr && p->next->data != e) {
            p = p->next;
        }
        if (p->next->data == e) {
            Node *q = p->next;
            p->next = q->next;
            delete q;
        }
    }

    // 打印
    inline void print(LinkedList &head) {
        Node *p = head;
        while (p->next != nullptr) {
            std::cout << p->next->data.number << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

    // 判空
    inline bool is_empty(LinkedList &head) {
        return head->next == nullptr;
    }

    // 销毁
    inline void destroy(LinkedList &head) {
        Node *p = head;
        while (p->next != nullptr) {
            Node *q = p->next;
            p->next = q->next;
            delete q;
        }
        delete head;
    }

}

#endif //LINEAR_LIST_LINKED_LIST_H
