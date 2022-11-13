#include <stdio.h>

#define DATA_TYPE double
#define FIRST 1.

void print_matrix_lo(DATA_TYPE* logical_arr, int row, int col, int page)
{
    printf("logical matrix of C:\n");
    for (int i = 0; i < page; i++)
    {
        printf("\tpage [%d]\n", i);
        for (int j = 0; j < col; j++)
        {
            printf("\t\tline [%d]\n\t\t", j);
            for (int k = 0; k < row; k++, logical_arr++)
                printf("\trow[%2d]: value{%4.1f} address: %10u", k, *logical_arr, logical_arr);
            printf("\n");
        }
    }
}

void print_matrix_phy(DATA_TYPE* phygical_arr, int count)
{
    printf("phygical matrix of C:\n");
    for (int i = 0; i < count; i++, phygical_arr++)
        if(i%4 != 3)
            printf("\trow[%2d]: value{%4.1f} address: %10u", i, *phygical_arr, phygical_arr);
        else
            printf("\trow[%2d]: value{%4.1f} address: %10u\n", i, *phygical_arr, phygical_arr);
    printf("\n");
}

int main(void)
{
    DATA_TYPE arr[2][2][3];

    for (int i = 0; i < 2 * 2 * 3; i++)
        arr[0][0][i] = i + FIRST;


    print_matrix_lo(arr, 3, 2, 2);
    printf("\n\n");
    print_matrix_lo(arr, 3, 2, 1);
    printf("\n\n");
    print_matrix_phy(arr, 3 * 2 * 2);
    printf("\n\n");
    print_matrix_phy(arr, 3 * 2);
}