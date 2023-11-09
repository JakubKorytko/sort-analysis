// Copyright: 2023 Jakub Korytko

#include "algorithms/quick_sort.h"

void _quick_sort(int *arr, int left, int right) {
  int i = left - 1, j = right + 1;
  int pivot = arr[(left + right) / 2];

  while (1) {
    while (arr[++i] < pivot) continue;

    while (arr[--j] > pivot) continue;

    if (i <= j) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    } else {
      break;
    }
  }

  if (left < j) {
    _quick_sort(arr, left, j);
  }

  if (right > i) {
    _quick_sort(arr, i, right);
  }
}

// Wrapper function to adjust the parameters to other functions
void quick_sort(int *arr, int n) { _quick_sort(arr, 0, n - 1); }
