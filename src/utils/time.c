// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <time.h>

#include "utils/time.h"

double measure_time(void (*function)(int *, int), int *arr, int n) {
    clock_t start, end;

    start = clock();
    function(arr, n);
    end = clock();

    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC * 1e+6;

    return elapsed;
}
