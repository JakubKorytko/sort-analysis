// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../headers/algorithms.h"
#include "../headers/utils/read.h"
#include "../headers/utils/time.h"

#define RANGE_MIN -100
#define RANGE_MAX 100
#define FILENAME "data"

void remove_spaces_from_string(char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i];
    str[count] = '\0';
}

char * algorithm_name_without_spaces(char *algorithm_name) {
    char *_algorithm_name = (char *)malloc(
        (strlen(algorithm_name) + 1) * sizeof(char));

    snprintf(_algorithm_name, strlen(algorithm_name) + 1,
    "%s", algorithm_name);

    remove_spaces_from_string(_algorithm_name);

    return _algorithm_name;
}

int *test1(int N) {
    int *array = (int *)malloc(N * sizeof(int));
    array = read(N, FILENAME);

    return array;
}

int *test2(int N) {
    int range = RANGE_MAX - RANGE_MIN + 1;

    if (N <= 0 || range <= 0)
        return NULL;

    int iterations = N / range > 0 ? N / range : 1;  // <-100, 100> -> 201
    int additional = N % range;
    int index = 0;

    int *array = (int *)malloc(N * sizeof(int));

    for (int i = RANGE_MIN; i <= RANGE_MAX; i++) {
        if (index >= N)
            break;
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

int main(int argc, char *argv[]) {
    FILE *results;

    int steps = argc > 1 ? atoi(argv[1]) : 7;
    char *filename = argc > 2 ? argv[2] : "data";

    int checked[6] = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < argc - 3; i++) {
        int index = atoi(argv[i + 3]);
        if (index >= 0 && index < 6)
            checked[index] = 1;
    }

    for (int i = 0; i < 6; i++) {
        if (!checked[i])
            continue;

        char *algorithm_name = algorithm_name_without_spaces(algorithms[i]);

        size_t results_filename_size = strlen(algorithm_name) + 13;

        char *results_filename = (char *)malloc(
            results_filename_size * sizeof(char));

        snprintf(results_filename, results_filename_size * sizeof(char),
        "results/%s.txt", algorithm_name);

        results = fopen(results_filename, "w");

        if (results == NULL) {
            printf("Failed to open %s file\n", results_filename);

            if (results_filename)
                free(results_filename);

            if (algorithm_name)
                free(algorithm_name);

            exit(1);
        }

        printf("Running \"%s\"...", algorithms[i]);

        fprintf(results, ">> %ssort <<\n\n", algorithms[i]);


        for (int k = 0; k < 3; k++) {
            printf("test %d/%d...", k + 1, 3);
            fprintf(results, "[Test %d]\n\n", k + 1);

            for (int j = 9; j < 9+steps; j++) {
                int base[3] = {1, 2, 5};

                int p = lround(pow(10, j / 3));
                int N = base[j % 3] * p;


                printf("N = %d...", N);
                fprintf(results, "N = %d: ", N);

                int *array = (int *)malloc(N * sizeof(int));
                array = tests[k](N);

                double time = measure_time(sort[i], array, N);

                if (time < 1)
                    fprintf(results, "less than 1 microsecond.\n");
                else
                    fprintf(results, "%.0f microseconds.\n", time);

                printf("OK! ");

                if (array)
                    free(array);
            }

            printf("\n\n");
            fprintf(results, "\n\n");
        }

        fclose(results);

        if (results_filename)
            free(results_filename);

        if (algorithm_name)
            free(algorithm_name);
    }

    return 0;
}
