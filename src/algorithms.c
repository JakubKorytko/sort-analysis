// Copyright: 2023 Jakub Korytko

#include "./algorithms.h"

void (*sort[])(int *, int) = {
    insertion_sort,
    selection_sort,
    bubble_sort,
    quick_sort,
    shell_sort,
    heap_sort
};

char *algorithms[] = {
    "Insertion sort",
    "Selection sort",
    "Bubble sort",
    "Quicksort",
    "Shellsort",
    "Heapsort"
};
