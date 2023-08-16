//
// 找到第k小的数
// 测试
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "kth_small.h"

void kth_small::test_kth_small() {
    const int size = 20;
    int arr[size];

    std::srand(std::time(nullptr));

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int k = 3;
    int kth = kth_small::kth_small(arr, 0, size - 1, k - 1);

    std::cout << "The " << k << "th smallest element is: " << kth << std::endl;
}

