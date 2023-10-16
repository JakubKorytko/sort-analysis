// Copyright: 2023 Jakub Korytko

#ifndef HEADERS_ALGORITHMS_H_
#define HEADERS_ALGORITHMS_H_

void insertion_sort(int *arr, int n);

void selection_sort(int *arr, int n);

void bubble_sort(int *arr, int n);

void quick_sort(int *arr, int left, int right);

void shell_sort(int *arr, int n);

void heap_sort(int *arr, int n);

void quick_sort_wrapper(int *arr, int n);

extern void (*sort[])(int *, int);

extern char *algorithms[];

#endif  // HEADERS_ALGORITHMS_H_
