//
// 找到第k小的数
// 实现
//

#ifndef SORT_KTH_SMALL_H
#define SORT_KTH_SMALL_H

#include <iostream>

namespace kth_small {

    inline void test_kth_small();

    inline int partition(int *arr, int low, int high) {
        int pivot = arr[low];
        while (low < high) {
            while (high > low && arr[high] >= pivot)
                high--;
            arr[low] = arr[high];
            while (low < high && arr[low] <= pivot)
                low++;
            arr[high] = arr[low];
        }
        arr[low] = pivot;
        return low;
    }

    inline int kth_small(int *arr, int low, int high, int k) {
        int mid = partition(arr, low, high);
        if (mid == k) {
            return arr[mid];
        }
        if (mid > k)
            return kth_small(arr, low, mid - 1, k);
        if (mid < k)
            return kth_small(arr, mid + 1, high, k);
    }

    inline void printArray(int *arr, int size) {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

}

#endif //SORT_KTH_SMALL_H
