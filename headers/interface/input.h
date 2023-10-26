// Copyright: 2023 Jakub Korytko

#ifndef HEADERS_INTERFACE_INPUT_H_
#define HEADERS_INTERFACE_INPUT_H_

int run_all_algorithms(int *arr, int n);

int get_single_char(void);

double get_sorting_time(int choice, int *arr, int n);

int run_algorithm(int choice, int *arr, int n, int clear);

void get_user_choice(int *choice);

int menu(int *arr, int n, int show_tab);

#endif  // HEADERS_INTERFACE_INPUT_H_
