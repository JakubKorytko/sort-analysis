// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include "../headers/print.h"

void clear_stream(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) continue;
}

int get_single_char(void) {
    int input;
    input = getchar();
    if (input != '\n') {
        clear_stream();
    }
    return input;
}

int color_printf(char *text, int color) {
    printf("\033[0;%dm%s\033[0m", color, text);
}

int num_printf(int number, int color) {
    printf("\033[0;%dm%d\033[0m", color, number);
}

void print_tab(int *arr, int n) {
    color_printf("[", 33);
    for (int i = 0; i < n; i++) {
        num_printf(arr[i], 33);
        if (i < n - 1) {
            color_printf(", ", 33);
        }
    }
    color_printf("]", 33);
}

void pause(int clear) {
    color_printf("\nPress ENTER to continue...", 36);
    if (clear)
        clear_stream();
    get_single_char();
}
