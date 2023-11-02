// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <stdlib.h>

#include "./logic.h"

#include "interface/output.h"
#include "utils/read.h"
#include "interface/input.h"

void validator(int res, char term, int N) {
    if ( (res == 2 && term == '\n') || N < 0 ) {
        negative_array_size_message();
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
