// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <stdio.h>
#include <string.h>

#include "../headers/print.h"
#include "../headers/menu.h"
#include "../headers/time.h"
#include "../headers/algorithms.h"

int file_data_display(int *arr, int n, int clear) {
    color_printf("\nAn array extracted from \"data\" file: ", 36);
    print_tab(arr, n);
    printf("\n");
    pause(clear);
}

int run_algorithm(int choice, int *arr, int n, int clear) {
    if (choice > 0 && choice < 7) {
        printf("\n");

        char name[25];

        snprintf(name, sizeof(name), "%s", algorithms[choice - 1]);

        if (choice - 1 < 3) {
            snprintf(name, sizeof(name), " ");
        }

        snprintf(name, sizeof(name), "sort");

        color_printf(name, 31);

        printf(" has been selected");

        printf(".\n\nSorted array: ");

        double time = measure_time(sort[choice - 1], arr, n);

        print_tab(arr, n);

        if (time < 1) {
            printf("\n\nSorting time: less than 1 microsecond.\n");
        } else {
            printf("\n\nSorting time: %.0f microseconds.\n", time);
        }
        pause(clear);
    } else {
        if (choice == 0) {
            color_printf("\n--- End of program ---\n", 31);
        } else if (choice == 7) {
            file_data_display(arr, n, 1);
        } else if (choice == 8) {
            clear_stream();
            for (int i = 0; i < 6; i++) {
                int res = run_algorithm(i + 1, arr, n, 0);
                if (res == -1)
                    return -1;
            }
        } else if (choice == 9) {
            color_printf("\n--- Program restart ---\n", 36);
        } else {
            color_printf("Incorrect choice.\n", 31);
            choice = -1;
        }
    }

    return choice;
}

int menu(int *arr, int n, int show_tab) {
    int choice;

    if (show_tab == 1) {
        color_printf("\n--- Array sorting program ---\n", 36);
        file_data_display(arr, n, 0);
    }

    color_printf("\nSelect a sorting algorithm:\n", 34);

    for (int i = 1; i <= 6; i++) {
        if (i == 1 || i == 4) {
            color_printf("\n--- Group ", 33);
            if (i == 4)
                color_printf("I", 33);
            color_printf("I ---\n\n", 33);
        }

        char name[25];


        snprintf(name, sizeof(name), "%s", algorithms[i - 1]);

        if (i - 1 < 3) {
            snprintf(name, sizeof(name), " ");
        }

        printf("%d. %ssort\n", i, name);

        if (i == 3 || i == 6)
            color_printf("\n---\n", 33);
    }

    color_printf("\n7. Print the loaded array", 36);
    color_printf("\n8. Run all algorithms one by one", 36);
    color_printf("\n9. Restart of the program (provide new array size)", 36);
    color_printf("\n0. Exit\n", 31);

    color_printf("\nChoice: ", 32);


    int res = scanf("%d", &choice);

    if (res == 0) {
        color_printf("Incorrect choice.\n", 31);
        clear_stream();
        return -1;
    }


    return run_algorithm(choice, arr, n, 1);
}
