#include <stdio.h>
#include <stdlib.h>

#include "./headers/logic.h"
#include "./headers/read.h"

int main()
{
    do
    {
        int N = -1;
        char term;

        while (N < 0) {

            printf("\nArray size: ");
            int res = scanf("%d", &N, &term);
            
            validator(res, term, N);
        }

        int *array = (int *)malloc(N * sizeof(int));
        array = read_data(N);

        if (main_loop(array, N) == 0)
            break;

        if (array)
            free(array);

    } while (1);

    return 0;
}