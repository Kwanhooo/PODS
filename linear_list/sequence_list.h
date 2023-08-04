//
// 线性表 - 顺序表
// 实现
//

#ifndef LINEAR_LIST_SEQUENCE_LIST_H
#define LINEAR_LIST_SEQUENCE_LIST_H

/**
 * 1. 数据结构定义
 */

#include <iostream>

#define MAX_CAPACITY 10

// 数据节点
typedef struct Element {
    int number;

    // 重载运算符
    bool operator==(const Element &other) const {
        return this->number == other.number;
    }

    bool operator!=(const Element &other) const {
        return this->number != other.number;
    }
} Element;

// 静态分配顺序表
typedef struct {
    Element data[MAX_CAPACITY];
    int length;
} SequenceList;


/**
 * 2. 基本操作
 */

// 初始化
void init(SequenceList &list) {
    list.length = 0;
}

// 求表长
int length(SequenceList list) {
    return list.length;
}

// 查找
int locate(SequenceList list, Element ele) {
    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] == ele) {
            return i;
        }
    }
    return -1;
}

// 打印
void print(SequenceList list) {
    std::cout << std::endl << "当前表长：" << list.length << std::endl;
    for (int i = 0; i < list.length; ++i) {
        std::cout << list.data[i].number << std::endl;
    }
}

// 按位查找
Element *get(SequenceList &list, int pos) {
    if (pos < 0 || pos >= list.length) {
        std::cout << std::endl << "范围错误 @查找" << std::endl;
        return nullptr;
    }
    return &(list.data[pos]);
}

// 插入
bool insert(SequenceList &list, Element ele, int pos) {
    // 检查范围
    if (pos < 0 || pos > list.length) {
        std::cout << std::endl << "范围错误 @插入" << std::endl;
        return false;
    }
    // 挪动位置
    for (int i = list.length - 1; i >= pos; --i) {
        list.data[i + 1] = list.data[i];
    }
    // 填充
    list.data[pos] = ele;
    // 长度增加
    list.length++;
    return true;
}

// 删除
Element *remove(SequenceList &list, int pos) {
    if (pos < 0 || pos >= list.length) {
        std::cout << std::endl << "范围错误 @删除" << std::endl;
        return nullptr;
    }
    Element *temp = &(list.data[pos]);
    for (int i = pos; i < list.length; ++i) {
        list.data[i] = list.data[i + 1];
    }
    list.length--;
    return temp;
}

// 判空
bool empty(SequenceList list) {
    return list.length == 0;
}

// 销毁
void destroy(SequenceList &list) {
    // do nothing
}

#endif //LINEAR_LIST_SEQUENCE_LIST_H
