// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <stdio.h>
#include <string.h>

#include "../headers/print.h"
#include "../headers/menu.h"
#include "../headers/time.h"
#include "../headers/algorithms.h"

int file_data_display(int *arr, int n, int clear) {
    color_printf("\nAn array extracted from \"data\" file: ", CYAN);
    print_tab(arr, n);
    printf("\n");
    pause(clear);
}

int run_algorithm(int choice, int *arr, int n, int clear) {
    if (choice > 0 && choice < 7) {
        printf("\n");

        color_printf(algorithms[choice - 1], YELLOW);

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
            color_printf("\n--- End of program ---\n", RED);
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
            color_printf("\n--- Program restart ---\n", CYAN);
        } else {
            color_printf("Incorrect choice.\n", RED);
            choice = -1;
        }
    }

    return choice;
}

int menu(int *arr, int n, int show_tab) {
    int choice;

    if (show_tab == 1) {
        color_printf("\n--- Array sorting program ---\n", CYAN);
        file_data_display(arr, n, 0);
    }

    color_printf("\nSelect a sorting algorithm:\n", BLUE);

    for (int i = 1; i <= 6; i++) {
        if (i == 1 || i == 4) {
            color_printf("\n--- Group ", YELLOW);
            if (i == 4)
                color_printf("I", YELLOW);
            color_printf("I ---\n\n", YELLOW);
        }

        printf("%d. %s\n", i, algorithms[i - 1]);

        if (i == 3 || i == 6)
            color_printf("\n---\n", YELLOW);
    }

    color_printf("\n7. Print the loaded array", CYAN);
    color_printf("\n8. Run all algorithms one by one", CYAN);
    color_printf("\n9. Restart of the program (provide new array size)", CYAN);
    color_printf("\n0. Exit\n", RED);

    color_printf("\nChoice: ", GREEN);


    int res = scanf("%d", &choice);

    if (res == 0) {
        color_printf("Incorrect choice.\n", RED);
        clear_stream();
        return -1;
    }


    return run_algorithm(choice, arr, n, 1);
}
