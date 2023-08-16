//
// 双向冒泡排序
// 测试
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "e2e_bubble.h"

void e2e_bubble::test_e2e_bubble() {
    const int size = 10;
    int arr[size];

    std::srand(std::time(nullptr));

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    e2e_bubble::bubble(arr, size);

    std::cout << "Sorted array: ";
    printArray(arr, size);
}
