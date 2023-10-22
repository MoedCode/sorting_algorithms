#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * swap - swaps two integers
 * @x: pointer to the first integer
 * @y: pointer to the second integer
 * Return: void
 */
void swap(int *x, int *y) {
    int tmp;

    if (x == NULL || y == NULL)
        return;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

/**
 * hoare_partition - sorts the array portion according to start and end
 *
 * @array: pointer to the array
 * @start: index to start from
 * @end: index to end with
 * Return: index of the pivot
 */
int hoare_partition(int *array, int start, int end) {
    int pivot = array[start];
    int above_pivot = start - 1;
    int below_pivot = end + 1;

    while (1) {
        do {
            above_pivot++;
        } while (array[above_pivot] < pivot);

        do {
            below_pivot--;
        } while (array[below_pivot] > pivot);

        if (above_pivot >= below_pivot)
            return below_pivot;

        swap(&array[above_pivot], &array[below_pivot]);
        print_array(array, end - start + 1);
    }
}

/**
 * str_end_sort - recursive function that sorts the array using quicksort algorithm
 * @array: pointer to the array of integers to sort
 * @start: index to start array partition to order
 * @end: index to end array partition to order
 */
void str_end_sort(int *array, int start, int end) {
    if (start < end) {
        int pivot = hoare_partition(array, start, end);
        str_end_sort(array, start, pivot);
        str_end_sort(array, pivot + 1, end);
    }
}

/**
 * quick_sort - sorting array using recursive str_end_sort function
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size) {
    if (array == NULL || size < 2)
        return;

    str_end_sort(array, 0, size - 1);
}
