// Copyright: 2023 Jakub Korytko

#include "algorithms/heap_sort.h"

void heap_sort(int *arr, int n) {
    // In a binary tree, node indices are numbered starting from 1
    // For this reason, 1 must be subtracted at each reference to the array

    // Building a heap

    for (int i = 2; i <= n; i++) {
        int j = i;
        int k = j / 2;
        int temp = arr[i - 1];

        while (k > 0 && arr[k - 1] < temp) {
            arr[j - 1] = arr[k - 1];
            j = k;
            k = j / 2;
        }

        arr[j - 1] = temp;
    }

    // Disassembling the heap

    for (int i = n; i > 1; i--) {
        int temp = arr[i - 1];
        arr[i - 1] = arr[0];
        arr[0] = temp;

        int j = 1;
        int k = 2;
        int m;

        while (k < i) {
            if (k + 1 < i && arr[k] > arr[k - 1])
                m = k + 1;
            else
                m = k;

            if (arr[m - 1] <= temp)
                break;

            int temp = arr[j - 1];
            arr[j - 1] = arr[m - 1];
            arr[m - 1] = temp;

            j = m;
            k = j + j;
        }
    }
}
