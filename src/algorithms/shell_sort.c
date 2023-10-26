// Copyright: 2023 Jakub Korytko

#include "../../headers/algorithms/shell_sort.h"

void shell_sort(int *arr, int n) {
    int h;
    for ( h = 1; h < n; h *= 3+1 ) continue;;
    h = h/9;

    if (!h) h++;

    while (h != 0) {
        for (int i = n-h-1; i >= 0; i-=1) {
            int temp = arr[i];
            int j = i+h;
            while (j<n && temp>arr[j]) {
                arr[j - h] = arr[j];
                j += h;
            }
            arr[j - h] = temp;
        }
        h /= 3;
    }
}
