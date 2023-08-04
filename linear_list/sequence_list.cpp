//
// 线性表 - 顺序表
// 测试
//

#include "sequence_list.h"

int main() {
    SequenceList list;
    init(list);
    print(list);

    Element ele;
    ele.number = 1;
    insert(list, ele, 0);
    ele.number = 2;
    insert(list, ele, 1);
    ele.number = 3;
    insert(list, ele, 2);
    print(list);

    ele.number = 114514;
    insert(list, ele, 2);
    print(list);

    Element searchElement;
    searchElement.number = 3;
    std::cout << std::endl << "查找结果：" << locate(list, searchElement) << std::endl;

    remove(list, 2);
    remove(list, 2);
    remove(list, 1);
    remove(list, 0);
    print(list);

    insert(list, ele, 0);
    print(list);

    return 0;
}
