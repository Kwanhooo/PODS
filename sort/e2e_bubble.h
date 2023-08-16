//
// 双向冒泡排序
// 实现
//

#ifndef SORT_E2E_BUBBLE_H
#define SORT_E2E_BUBBLE_H

namespace e2e_bubble {

    inline void test_e2e_bubble();

    inline void bubble(int *arr, int size) {
        int front = 0;
        int end = size - 1;

        while (front < end) {
            for (int i = front; i < end; ++i) {
                if (arr[i] > arr[i + 1]) {
                    int tmp = arr[i + 1];
                    arr[i + 1] = arr[i];
                    arr[i] = tmp;
                }
            }
            end--;
            for (int i = end; i > front; --i) {
                if (arr[i] < arr[i - 1]) {
                    int tmp = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = tmp;
                }
            }
            front++;
        }
    }

    inline void printArray(int *arr, int size) {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
}

#endif //SORT_E2E_BUBBLE_H
