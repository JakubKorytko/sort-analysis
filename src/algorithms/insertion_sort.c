// Copyright: 2023 Jakub Korytko

#include "../../headers/algorithms/insertion_sort.h"

void insertion_sort(int *arr, int n) {
    for ( int i = n - 2; i >= 0; i-- ) {
        int x = arr[i];
        int j = i + 1;

        while (j<n && x>arr[j]) {
            arr[j - 1] = arr[j];
            j++;
        }

        arr[j - 1] = x;
    }
}
