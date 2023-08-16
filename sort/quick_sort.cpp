//
// 快速排序
// 测试
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "quick_sort.h"

void quick_sort::test_quick_sort() {
    const int size = 10;
    int arr[size];

    std::srand(std::time(nullptr));

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    quick_sort::quick_sort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    printArray(arr, size);
}

