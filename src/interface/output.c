// Copyright: 2023 Jakub Korytko

#include "interface/output.h"

#include <stdio.h>

#include "./algorithms.h"
#include "interface/input.h"
#include "utils/print.h"

void pause(int clear) {
  color_printf("\nPress ENTER to continue...", CYAN);
  if (clear) clear_stream();
  get_single_char();
}

void print_algorithm_selection(int choice) {
  printf("\n");

  color_printf(algorithms[choice - 1], YELLOW);

  printf(" has been selected.");

  printf("\n\nSorted array: ");
}

void print_menu(int *arr, int n, int show_tab) {
  show_welcome_message(arr, n, show_tab);

  color_printf("\nSelect a sorting algorithm:\n", BLUE);

  for (int i = 1; i <= 6; i++) {
    if (i == 1) {
      color_printf("\n--- Group I ---\n\n", YELLOW);
    }

    if (i == 4) {
      color_printf("\n--- Group II ---\n\n", YELLOW);
    }

    printf("%d. %s\n", i, algorithms[i - 1]);

    if (i == 3 || i == 6) color_printf("\n---\n", YELLOW);
  }

  color_printf("\n7. Print the loaded array", CYAN);
  color_printf("\n8. Run all algorithms one by one", CYAN);
  color_printf("\n9. Restart of the program (provide new array size)", CYAN);
  color_printf("\n0. Exit\n", RED);
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

void display_sorting_time(double time, int clear) {
  if (time < 1) {
    printf("\n\nSorting time: less than 1 microsecond.\n");
  } else {
    printf("\n\nSorting time: %.0f microseconds.\n", time);
  }

  pause(clear);
}

void display_file_not_found_message() {
  char message[6][100] = {
      "\nCannot open data file\n\n", "Make sure that: \n\n",
      "1. The data file is in the same folder as the executable file\n",
      "2. The file is named \"data\", without the extension.\n\n",

      // notice the lack of comma, it's intentional
      "If the file does not exist, create it"
      "and save numbers in it from the range <-100,100> ",

      "separated by space or enter and then run the program again\n"};

  color_printf(message[0], RED);
  printf("%s", message[1]);
  color_printf(message[2], YELLOW);
  color_printf(message[3], YELLOW);
  printf("%s%s", message[4], message[5]);
}

void negative_array_size_message() {
  printf("The size of the array must be a non-negative number!\n");
}

int file_data_display(int *arr, int n, int clear) {
  color_printf("\nAn array extracted from \"data\" file: ", CYAN);
  print_tab(arr, n);
  printf("\n");
  pause(clear);
}

void show_welcome_message(int *arr, int n, int show_tab) {
  if (show_tab == 1) {
    color_printf("\n--- Array sorting program ---\n", CYAN);
    file_data_display(arr, n, 0);
  }
}

void display_end_of_program_message() {
  color_printf("\n--- End of program ---\n", RED);
}

void display_program_restart_message() {
  color_printf("\n--- Program restart ---\n", CYAN);
}

void display_incorrect_choice_message() {
  color_printf("Incorrect choice.\n", RED);
}

void display_choice_message() { color_printf("\nChoice: ", GREEN); }

void display_array_size_message() { printf("\nArray size: "); }
