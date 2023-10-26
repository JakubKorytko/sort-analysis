// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <stdio.h>
#include <string.h>

#include "../../headers/interface/input.h"

#include "../../headers/utils/print.h"
#include "../../headers/utils/time.h"
#include "../../headers/interface/output.h"
#include "../../headers/algorithms.h"

int get_single_char(void) {
    int input;
    input = getchar();
    if (input != '\n') {
        clear_stream();
    }
    return input;
}

int run_all_algorithms(int *arr, int n) {
    clear_stream();
    for (int i = 0; i < 6; i++) {
        int res = run_algorithm(i + 1, arr, n, 0);

        if (res == -1) {
            return -1;
        }
    }

    return 1;
}

double get_sorting_time(int choice, int *arr, int n) {
    double time = measure_time(sort[choice - 1], arr, n);

    return time;
}

int run_algorithm(int choice, int *arr, int n, int clear) {
    // Algorithm options
    if (choice > 0 && choice < 7) {
        print_algorithm_selection(choice);
        print_tab(arr, n);

        double time = get_sorting_time(choice, arr, n);
        display_sorting_time(time, clear);

        return choice;
    }

    // Other options
    switch (choice) {
        case 0:
            display_end_of_program_message();
            break;
        case 7:
            file_data_display(arr, n, 1);
            break;
        case 8:
            return run_all_algorithms(arr, n);
            break;
        case 9:
            display_program_restart_message();
            break;
        default:
            display_incorrect_choice_message();
            choice = -1;
            break;
    }

    return choice;
}

void get_user_choice(int *choice) {
    display_choice_message();
    int res = scanf("%d", choice);

    if (res == 0) {
        display_incorrect_choice_message();
        clear_stream();
        *choice = -1;
    }
}

int menu(int *arr, int n, int show_tab) {
    int choice;

    print_menu(arr, n, show_tab);

    get_user_choice(&choice);

    return run_algorithm(choice, arr, n, 1);
}
