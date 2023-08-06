#include <iostream>

#include "sequence_stack.cpp"
#include "linked_stack.cpp"
#include "doubly_linked_stack.cpp"

int main() {
    std::cout << "---------- 顺序栈 ----------" << std::endl;
    sequence_stack::test_sequence_stack();
    std::cout << "---------------------------" << std::endl << std::endl << std::endl;

    std::cout << "----------- 链栈 -----------" << std::endl;
    linked_stack::test_linked_stack();
    std::cout << "---------------------------" << std::endl << std::endl << std::endl;

    std::cout << "--------- 双向链栈 ---------" << std::endl;
    doubly_linked_stack::test_doubly_linked_stack();
    std::cout << "---------------------------" << std::endl << std::endl << std::endl;

    return 0;
}
