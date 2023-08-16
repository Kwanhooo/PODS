//
// 将所有奇数移到偶数前面
// 测试
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "even_odd_carrier.h"

void even_odd_carrier::test_even_odd_carrier() {
    const int size = 10;
    int arr[size];

    std::srand(std::time(nullptr));

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    even_odd_carrier::sort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    printArray(arr, size);
}