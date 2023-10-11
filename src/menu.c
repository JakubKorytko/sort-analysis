#include <stdio.h>
#include <string.h>

#include "../headers/print.h"
#include "../headers/menu.h"
#include "../headers/time.h"
#include "../headers/algorithms.h"

int file_data_display(int *arr, int n, int clear)
{
    color_printf("\nAn array extracted from \"data\" file: ", 36);
    print_tab(arr, n);
    printf("\n");
    pause(clear);
}

int run_algorithm(int choice, int *arr, int n, int clear)
{
    
    if (choice > 0 && choice < 7)
    {

        printf("\n");

        char name[25]; 
        
        strcpy(name, algorithms[choice - 1]);

        if (choice - 1 < 3) {
            strcat(name, " ");
        }

        strcat(name, "sort");

        color_printf(name, 31);
        
        printf(" has been selected");

        printf(".\n\nSorted array: ");

        double time = measure_time(sort[choice - 1], arr, n);
        
        print_tab(arr, n);

        if (time < 1)
        {
            printf("\n\nSorting time: less than 1 microsecond.\n");
        }
        else
        {
            printf("\n\nSorting time: %.0f microseconds.\n", time);
        }
        pause(clear);
    }
    else
    {
        if (choice == 0)
            color_printf("\n--- End of program ---\n", 31);
        else if (choice == 7)
            file_data_display(arr, n, 1);
        else if (choice == 8) {
            clear_stream();
            for (int i = 0; i < 6; i++)
            {
                int res = run_algorithm(i + 1, arr, n, 0);
                if (res == -1)
                    return -1;
            }
        }
        else if (choice == 9) {
            color_printf("\n--- Program restart ---\n", 36);
        }
        else {
            color_printf("Incorrect choice.\n", 31);
            choice = -1;
        }
    }

    return choice;
}