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
