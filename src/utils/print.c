// Copyright: 2023 Jakub Korytko

#include "utils/print.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_coloring_enabled() {
  char *enable_coloring = getenv("ENABLE_COLORING");

  if (enable_coloring == NULL) {
    return 1;
  }

  if (strcmp(enable_coloring, "false") == 0) {
    return 0;
  }

  return 1;
}

void clear_stream(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) continue;
}

int color_printf(char *text, enum COLORS color) {
  if (!is_coloring_enabled()) return printf("%s", text);

  printf("\033[0;%dm%s\033[0m", color, text);
}

int num_printf(int number, enum COLORS color) {
  if (!is_coloring_enabled()) return printf("%d", number);

  printf("\033[0;%dm%d\033[0m", color, number);
}
