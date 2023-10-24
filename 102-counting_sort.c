#include "sort.h"
#include <stddef.h>
#include <stdlib.h>

 int getMaxInAr(int *array, size_t size)
{
	size_t i;
	int max = 0;

	if (!array || !size)
		return(-1);

	for ( i = 0, max = 0; i < size; i++)
	{
		if (max < array[i])
				max = array[i];
	}
	return (max);
}
void counting_sort(int *array, size_t size)
{
    int max = getMaxInAr(array, size);
    int *count_arr;
    int i, k = 0;
	count_arr = (int *)calloc(( max + 1), sizeof(int));
	if(!count_arr)
	return;


  for (i = 0; i < (int)size; i++)
    {
        count_arr[array[i]]++;
    }
    for (i = 0; i <= max; i++)
    {
        while (count_arr[i] > 0)
        {
            array[k] = i;
            k++;
            count_arr[i]--;
        }
    }


	print_array(count_arr, max + 1);
	free(count_arr);


}