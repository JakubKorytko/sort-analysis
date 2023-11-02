// Copyright: 2023 Jakub Korytko

#include <stdio.h>

#include "utils/print.h"

void clear_stream(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) continue;
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
