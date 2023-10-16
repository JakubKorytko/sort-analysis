// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <stdio.h>
#include <stdlib.h>

#include "../headers/read.h"
#include "../headers/print.h"

int * read(int number_of_elements, char *filename)  {
    char message[6][100] = {
        "\nCannot open data file\n\n",
        "Make sure that: \n\n",
        "1. The data file is in the same folder as the executable file\n",
        "2. The file is named \"data\", without the extension.\n\n",

        // notice the lack of comma, it's intentional
        "If the file does not exist, create it"
        "and save numbers in it from the range <-100,100> ",

        "separated by space or enter and then run the program again\n"};

    FILE *data;
    data = fopen(filename, "r");

    if (data == NULL) {
        color_printf(message[0], 31);
        printf("%s", message[1]);
        color_printf(message[2], 33);
        color_printf(message[3], 33);
        printf("%s%s", message[4], message[5]);
        exit(1);
    }

    int *numbers = (int *)malloc(number_of_elements * sizeof(int));

    for (int i = 0; i < number_of_elements; i++) {
        fscanf(data, "%d", &numbers[i]);
    }

    fclose(data);

    return numbers;
}

int * read_data(int N) {
    return read(N, "data");
}
