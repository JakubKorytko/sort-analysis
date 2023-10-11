#ifndef ALGORITHMS_H
#define ALGORITHMS_H

void insertion_sort(int *arr, int n);

void selection_sort(int *arr, int n);

void bubble_sort(int *arr, int n);

void quick_sort(int *arr, int left, int right);

void shell_sort(int *arr, int n);

void heap_sort(int *arr, int n);

void quick_sort_wrapper(int *arr, int n);

extern void (*sort[])(int *, int);

extern char *algorithms[];

#endif // ALGORITHMS_H