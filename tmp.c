#include <stddef.h>
#include <stdio.h>
#include <stdio.h>
#include "sort.h"
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

void insertionSort(int array[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
        print_array(array, size);
    }
}

int main(void)
{
    size_t size, i;
    int array[] =  {19, 48, 99, 71, 13, 52, 96, 73, 86, 7}, tmp;
    // int array1[] = {2, 5, 4, 10, 1, 5}, tmp1;
    size = sizeof(array) / sizeof(int);
    print_array(array, size);

    insertionSort(array, size);
    print_array(array, size);
    for ( i = 1; i < size; i++)
    {
        tmp = array[i];
        if (array[i - 1] > tmp)
            {
                array[0] = array[0];
            }
    }

    return (0);
}