//
// 主函数
//

#include "sequence_list.cpp"
#include "linked_list.cpp"

int main() {
    std::cout << "---------- 顺序表 ----------" << std::endl;
    sequence_list::test_sequence_list();
    std::cout << "---------------------------" << std::endl << std::endl << std::endl;

    std::cout << "---------- 单链表 ----------" << std::endl;
    linked_list::test_linked_list();
    std::cout << "---------------------------" << std::endl << std::endl << std::endl;

    return 0;
}