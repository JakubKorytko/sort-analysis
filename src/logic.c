// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <stdlib.h>

#include "../headers/print.h"
#include "../headers/read.h"
#include "../headers/logic.h"
#include "../headers/menu.h"


void validator(int res, char term, int N) {
    if ( (res == 2 && term == '\n') || N < 0 ) {
        printf("The size of the array must be a non-negative number!\n");
    }

    while ((term = getchar()) != '\n' && term != EOF) { }
}

int main_loop(int *array, int N) {
    int loop = 1;
    int first_iteration = 1;

    do {
        array = read_data(N);
        loop = menu(array, N, first_iteration);
        if (first_iteration)
            first_iteration = 0;
    } while (loop && loop != 9);

    return loop;
}
