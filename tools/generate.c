#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define min -100
#define max 100

int number(int from, int to) {
    return rand() % (to - from + 1) + from;
}

int main(int argc, char *argv[]) {

    int number_of_elements = argc > 1 ? atoi(argv[1]) : 100000;
    char *filename = argc > 2 ? argv[2] : "data";

    FILE *data;
    data = fopen(filename, "w");

    if (data == NULL) {
        printf("Failed to open %s file\n", filename);
        exit(1);
    }

    srand(time(NULL));

    printf("%s\n", filename);

    for (int i = 0; i < number_of_elements; i++) {
        fprintf(data, "%d", number(min, max));
        if (i < number_of_elements) {
            fprintf(data, " ");
        }
    }

    fclose(data);
}