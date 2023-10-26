// Copyright: 2023 Jakub Korytko

#ifndef HEADERS_ALGORITHMS_H_
#define HEADERS_ALGORITHMS_H_

#include "algorithms/selection_sort.h"
#include "algorithms/insertion_sort.h"
#include "algorithms/bubble_sort.h"
#include "algorithms/quick_sort.h"
#include "algorithms/shell_sort.h"
#include "algorithms/heap_sort.h"

extern void (*sort[])(int *, int);

extern char *algorithms[];

#endif  // HEADERS_ALGORITHMS_H_
