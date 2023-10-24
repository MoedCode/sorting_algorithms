#include "sort.h"
#include <stddef.h>

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
	int max = getMaxInAr(array, size),
	count_arr[max], i;
	for (i = 0; i < max; i++)
		count_arr[i] = 1;
	print_array(count_arr, max);
	printf("maix is [%d]", max);



}