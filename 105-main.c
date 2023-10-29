#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	int array2[] = {432, 8, 530, 90, 88, 231, 11, 45, 677, 199};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array2, n);
	printf("\n");
	radix_sort(array2, n);
	printf("\n");
	print_array(array2, n);
	return (0);
}