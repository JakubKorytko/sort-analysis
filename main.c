// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <stdio.h>
#include <stdlib.h>

#include "./headers/interface/output.h"
#include "./headers/logic.h"
#include "./headers/utils/read.h"

int main() {
  while (1) {
    int N = -1;

    while (N < 0) {
      display_array_size_message();
      int res = scanf("%d", &N);

      validator(res, N);
    }

    int *array = (int *)malloc(N * sizeof(int));
    array = read_data(N);

    if (main_loop(array, N) == 0) break;

    if (array) free(array);
  }

  return 0;
}
