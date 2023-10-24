#include "sort.h"
#include <stddef.h>

void getMaxInAr(int *array, size_t size, int *max)
{
	size_t i;

	if (!array || !size || !max)
		return;

	for ( i = 0, max = 0; i < size; i++)
	{
		if (*max < array[i])
			*max = array[i];
	}
}
void counting_sort(int *array, size_t size)
{
	int max;
	getMaxInAr(array, size, &max);
	printf("maix is [%d]", (int)max);

}