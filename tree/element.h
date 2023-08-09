//
// 数据节点
//

#ifndef LINEAR_LIST_ELEMENT_H
#define LINEAR_LIST_ELEMENT_H

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

#endif //LINEAR_LIST_ELEMENT_H
