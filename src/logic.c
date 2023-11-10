// Copyright: 2023 Jakub Korytko

#include "./logic.h"

#include <stdio.h>
#include <stdlib.h>

#include "interface/input.h"
#include "interface/output.h"
#include "utils/read.h"

void validator(int res, int N) {
  if (res == 2 || N < 0) {
    negative_array_size_message();
  }

  char term;

  while ((term = getchar()) != '\n' && term != EOF) {
  }
}

int main_loop(int *array, int N) {
  int loop = 1;
  int first_iteration = 1;

  do {
    array = read_data(N);
    loop = menu(array, N, first_iteration);
    if (first_iteration) first_iteration = 0;
  } while (loop && loop != 9);

  return loop;
}
