#include "sort.h"


void bubble_sort(int *array, size_t size)
{
    int is_swp = 1, tmp;  /* Set initially to 1 to ensure at least one pass */
    size_t i;

    if(!array || !size || size < 2)
        return;

    while (is_swp)
    {
        is_swp = 0;  /* Reset the flag at the beginning of each pass */
        for (i = 0; i < size - 1; ++i)
        {
            if (array[i] > array[i + 1])
            {
                tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                is_swp = 1;  /* Set the flag if a swap occurred */
				print_array(array, size);
            }
        }
    }
}