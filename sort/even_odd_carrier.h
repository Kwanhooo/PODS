//
// 将所有奇数移到偶数前面
// 实现
//

#ifndef SORT_EVEN_ODD_CARRIER_H
#define SORT_EVEN_ODD_CARRIER_H

namespace even_odd_carrier {

    inline void test_even_odd_carrier();

    inline bool compare(int a, int b) {
        return !(a % 2 == 1 && b % 2 == 0);
    }

    inline int partition(int *arr, int low, int high) {
        int pivot = arr[low];
        while (low < high) {
            while (high > low && compare(arr[high], pivot))
                high--;
            arr[low] = arr[high];
            while (low < high && compare(pivot, arr[low]))
                low++;
            arr[high] = arr[low];
        }
        arr[low] = pivot;
        return low;
    }

    inline void sort(int *arr, int low, int high) {
        if (low > high)
            return;
        int mid = partition(arr, low, high);
        sort(arr, low, mid - 1);
        sort(arr, mid + 1, high);
    }

    inline void printArray(int *arr, int size) {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
}

#endif //SORT_EVEN_ODD_CARRIER_H
