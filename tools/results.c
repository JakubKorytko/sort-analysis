// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./algorithms.h"
#include "interface/output.h"
#include "utils/read.h"
#include "utils/time.h"

#define RANGE_MIN -100
#define RANGE_MAX 100

static char *filename;
static int checked[6];
static int steps;

int *test1(int N) {
  int *array = (int *)malloc(N * sizeof(int));
  array = read(N, filename);

  return array;
}

int *test2(int N) {
  int range = RANGE_MAX - RANGE_MIN + 1;

  if (N <= 0 || range <= 0) return NULL;

  int iterations = N / range > 0 ? N / range : 1;  // <-100, 100> -> 201
  int additional = N % range;
  int index = 0;

  int *array = (int *)malloc(N * sizeof(int));

  for (int i = RANGE_MIN; i <= RANGE_MAX; i++) {
    if (index >= N) break;
    for (int j = 0; j < iterations; j++) {
      array[index++] = i;
    }
    if (additional > 0) {
      array[index++] = i;
      additional--;
    }
  }

  return array;
}

int *test3(int N) {
  int *array = (int *)malloc(N * sizeof(int));
  array = test2(N);

  for (int i = 0; i < N / 2; i++) {
    int temp = array[i];
    array[i] = array[N - 1 - i];
    array[N - 1 - i] = temp;
  }

  return array;
}

int *(*tests[])(int) = {test1, test2, test3};

void remove_spaces_from_string(char *str) {
  int count = 0;
  for (int i = 0; str[i]; i++)
    if (str[i] != ' ') str[count++] = str[i];
  str[count] = '\0';
}

char *algorithm_name_without_spaces(char *algorithm_name) {
  char *_algorithm_name =
      (char *)malloc((strlen(algorithm_name) + 1) * sizeof(char));

  snprintf(_algorithm_name, strlen(algorithm_name) + 1, "%s", algorithm_name);

  remove_spaces_from_string(_algorithm_name);

  return _algorithm_name;
}

FILE *open_results_file(char *algorithm_name) {
  FILE *results_file;

  char *algorithm_name_no_spaces =
      algorithm_name_without_spaces(algorithm_name);

  size_t results_filename_size = strlen(algorithm_name_no_spaces) + 13;

  char *results_filename = (char *)malloc(results_filename_size * sizeof(char));

  snprintf(results_filename, results_filename_size * sizeof(char),
           "results/%s.txt", algorithm_name_no_spaces);

  results_file = fopen(results_filename, "w");

  if (results_filename) free(results_filename);

  if (algorithm_name_no_spaces) free(algorithm_name_no_spaces);

  if (results_file == NULL) {
    printf("Failed to open %s file\n", results_filename);
    exit(1);
  }

  return results_file;
}

void write_time(FILE *results_file, double time) {
  if (time < 1)
    fprintf(results_file, "less than 1 microsecond.\n");
  else
    fprintf(results_file, "%.0f microseconds.\n", time);
}

int get_elements_count(int steps) {
  int base[3] = {1, 2, 5};

  int exponent = steps / 3;
  int base_index = steps % 3;

  // + 3 because we want to start from minimum 1000 elements
  int multiplier = lround(pow(10, exponent + 3));
  int elements = base[base_index] * multiplier;

  return elements;
}

void generate_sort_target_array(int argc, char *argv[]) {
  for (int i = 0; i < argc - 3; i++) {
    int index = atoi(argv[i + 3]);
    if (index >= 0 && index < 6) checked[index] = 1;
  }
}

void process_command_arguments(int argc, char *argv[]) {
  steps = argc > 1 ? atoi(argv[1]) : 5;
  filename = argc > 2 ? argv[2] : "data";

  for (int i = 0; i < 6; i++) {
    checked[i] = argc > 3 ? 0 : 1;
  }

  generate_sort_target_array(argc, argv);
}

void write_sort_result(FILE *results_file, int test_number, int sort_index,
                       int steps) {
  int N = get_elements_count(steps);

  printf("N = %d...", N);
  fprintf(results_file, "N = %d: ", N);

  int *array = (int *)malloc(N * sizeof(int));
  array = tests[test_number](N);

  double time = measure_time(sort[sort_index], array, N);

  write_time(results_file, time);

  printf("OK! ");

  if (array) free(array);
}

int main(int argc, char *argv[]) {
  FILE *results;

  process_command_arguments(argc, argv);

  for (int i = 0; i < 6; i++) {
    if (!checked[i]) continue;

    results = open_results_file(algorithms[i]);

    printf("Running \"%s\"...", algorithms[i]);
    fprintf(results, ">> %ssort <<\n\n", algorithms[i]);

    for (int k = 0; k < 3; k++) {
      printf("test %d/%d...", k + 1, 3);
      fprintf(results, "[Test %d]\n\n", k + 1);

      for (int j = 0; j < steps; j++) {
        write_sort_result(results, k, i, j);
      }

      printf("\n\n");
      fprintf(results, "\n\n");
    }

    fclose(results);
  }

  return 0;
}
