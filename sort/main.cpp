#include "quick_sort.cpp"
#include "e2e_bubble.cpp"
#include "even_odd_carrier.cpp"
#include "kth_small.cpp"

int main() {
    quick_sort::test_quick_sort();
    e2e_bubble::test_e2e_bubble();
    even_odd_carrier::test_even_odd_carrier();
    kth_small::test_kth_small();
    return 0;
}
