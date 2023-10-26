// Copyright: 2023 Jakub Korytko

#ifndef HEADERS_INTERFACE_OUTPUT_H_
#define HEADERS_INTERFACE_OUTPUT_H_

void print_algorithm_selection(int choice);

void print_menu();

void print_tab(int *arr, int n);

void display_sorting_time(double time, int clear);

void display_file_not_found_message();

void negative_array_size_message();

int file_data_display(int *arr, int n, int clear);

void show_welcome_message(int *arr, int n, int show_tab);

void display_array_size_message();

void display_end_of_program_message();

void display_program_restart_message();

void display_incorrect_choice_message();

void display_choice_message();

void display_array_size_message();

#endif  // HEADERS_INTERFACE_OUTPUT_H_
