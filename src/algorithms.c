#include "../headers/algorithms.h"

void insertion_sort(int *arr, int n) {
    for (int i = n - 2; i>=0; i--) {

        int x = arr[i];
        int j = i + 1;

        while (j<n && x>arr[j]) {
            arr[j - 1] = arr[j];
            j++;
        }

        arr[j - 1] = x;
    }
}

void selection_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++ ) {  
        int min = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quick_sort(int *arr, int left, int right) {
    int i = left - 1, j = right + 1;
    int pivot = arr[(left + right) / 2];

    while (1) {
        while (arr[++i] < pivot);

        while (arr[--j] > pivot);

        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } else break;
    }

    if (left < j) {
        quick_sort(arr, left, j);
    }

    if (right > i) {
        quick_sort(arr, i, right);
    }
}


void shell_sort(int *arr, int n) {
    int h;
    for (h = 1; h<n; h*=3+1);
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

void quick_sort_wrapper(int *arr, int n) {quick_sort(arr, 0, n-1);}

void (*sort[])(int *, int) = {insertion_sort, selection_sort, bubble_sort, quick_sort_wrapper, shell_sort, heap_sort};

char *algorithms[] = {"Insertion", "Selection", "Bubble", "Quick", "Shell", "Heap"};
