// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include "../headers/print.h"

#define ENABLE_COLORING 1

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

int color_printf(char *text, enum COLORS color) {
    if (!ENABLE_COLORING)
        return printf("%s", text);

    printf("\033[0;%dm%s\033[0m", color, text);
}

int num_printf(int number, enum COLORS color) {
    if (!ENABLE_COLORING)
        return printf("%d", number);

    printf("\033[0;%dm%d\033[0m", color, number);
}

void print_tab(int *arr, int n) {
    color_printf("[", YELLOW);
    for (int i = 0; i < n; i++) {
        num_printf(arr[i], YELLOW);
        if (i < n - 1) {
            color_printf(", ", YELLOW);
        }
    }
    color_printf("]", YELLOW);
}

void pause(int clear) {
    color_printf("\nPress ENTER to continue...", CYAN);
    if (clear)
        clear_stream();
    get_single_char();
}
