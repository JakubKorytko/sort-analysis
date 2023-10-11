#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../headers/algorithms.h"
#include "../headers/read.h"
#include "../headers/time.h"

#define RANGE_MIN -100
#define RANGE_MAX 100
#define FILENAME "data"

int *test1(int N)
{

    int *array = (int *)malloc(N * sizeof(int));
    array = read(N, FILENAME);

    return array;
}

int *test2(int N)
{

    int range = RANGE_MAX - RANGE_MIN + 1;

    if (N <= 0 || range <= 0)
        return NULL;

    int iterations = N / range > 0 ? N / range : 1; // <-100, 100> -> 201
    int additional = N % range;
    int index = 0;

    int *array = (int *)malloc(N * sizeof(int));

    for (int i = RANGE_MIN; i <= RANGE_MAX; i++)
    {
        if (index >= N)
            break;
        for (int j = 0; j < iterations; j++)
        {
            array[index++] = i;
        }
        if (additional > 0)
        {
            array[index++] = i;
            additional--;
        }
    }

    return array;
}

int *test3(int N)
{

    int *array = (int *)malloc(N * sizeof(int));
    array = test2(N);

    for (int i = 0; i < N / 2; i++)
    {
        int temp = array[i];
        array[i] = array[N - 1 - i];
        array[N - 1 - i] = temp;
    }

    return array;
}

int *(*tests[])(int) = {test1, test2, test3};

int main(int argc, char *argv[])
{
    FILE *results;

    int steps = argc > 1 ? atoi(argv[1]) : 7;
    char *filename = argc > 2 ? argv[2] : "data";

    int checked[6] = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < argc - 3; i++)
    {
        int index = atoi(argv[i + 3]);
        if (index >= 0 && index < 6)
            checked[index] = 1;
    }

    for (int i = 0; i < 6; i++)
    {

        if (!checked[i])
            continue;

        char *results_filename = malloc(40 * sizeof(char));

        strcpy(results_filename, "results/");
        strcat(results_filename, algorithms[i]);
        strcat(results_filename, ".txt");

        printf("%s", results_filename);

        results = fopen(results_filename, "w");

        if (results == NULL) {
            printf("Failed to open %s file\n", results_filename);
            exit(1);
        }

        char name[25]; 
        
        strcpy(name, algorithms[i]);

        if (i < 3) {
            strcat(name, " ");
        }

        strcat(name, "sort");

        printf("Running \"%s\"...", name);

        fprintf(results, ">> %ssort <<\n\n", name);


        for (int k = 0; k < 3; k++)
        {
            printf("test %d/%d...", k + 1, 3);
            fprintf(results, "[Test %d]\n\n", k + 1);

            for (int j = 9; j < 9+steps; j++)
            {
                int base[3] = {1,2,5};

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
    }

    return 0;
}
