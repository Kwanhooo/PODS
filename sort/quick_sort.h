//
// 快速排序
// 实现
//

#ifndef SORT_QUICK_SORT_H
#define SORT_QUICK_SORT_H

namespace quick_sort {

    inline void test_quick_sort();

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

    inline void quick_sort(int *arr, int low, int high) {
        if (low > high)
            return;
        int mid = partition(arr, low, high);
        quick_sort(arr, low, mid - 1);
        quick_sort(arr, mid + 1, high);
    }

    inline void printArray(int *arr, int size) {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

}

#endif //SORT_QUICK_SORT_H
