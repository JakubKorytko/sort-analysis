// Copyright: 2023 Jakub Korytko

// ╔══════════════════════════╗
// ║       Color codes        ║
// ╠══════════════════════════╣
// ║ 30 - black ║ 31 - red    ║
// ║ 32 - green ║ 33 - yellow ║
// ║ 34 - blue  ║ 35 - purple ║
// ║ 36 - cyan  ║ 37 - white  ║
// ║ 0 - reset  ║             ║
// ╚════════════╩═════════════╝

#ifndef HEADERS_UTILS_PRINT_H_
#define HEADERS_UTILS_PRINT_H_

#define ENABLE_COLORING 1

typedef enum COLORS {
    BLACK = 30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    CYAN,
    WHITE,

    RESET = 0
} COLORS;

void clear_stream(void);

int color_printf(char *text, enum COLORS color);

int num_printf(int number, enum COLORS color);

#endif  // HEADERS_UTILS_PRINT_H_
