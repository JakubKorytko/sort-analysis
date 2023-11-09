// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include "utils/read.h"

#include <stdio.h>
#include <stdlib.h>

#include "interface/output.h"

int *read(int number_of_elements, char *filename) {
  FILE *data;
  data = fopen(filename, "r");

  if (data == NULL) {
    display_file_not_found_message();
    exit(1);
  }

  int *numbers = (int *)malloc(number_of_elements * sizeof(int));

  for (int i = 0; i < number_of_elements; i++) {
    fscanf(data, "%d", &numbers[i]);
  }

  fclose(data);

  return numbers;
}

int *read_data(int N) { return read(N, "data"); }
