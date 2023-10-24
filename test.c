#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
int gl_size = 0;
void qs(int arr[], int left, int right);
// Function to print the array
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

// Function to swap two elements
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int *arr, int start, int end)
{
	int pivot = arr[end];

	int i = start - 1, j; // printf("start %i\n", i);
	// printf("pivot %i  ", pivot);

	for (j = start; j < end; j++)
	{
		if (arr[j] < pivot)
		{

			i++;
			/*make sure not to swap if both j and i are equal*/
			/* to eliminate unnecessary swaps*/
			if ((i < j))
			{

				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
				print_array(arr, gl_size);
			}
		}
	}

	i++;
	/*make sure that arr[i] is not the pivot*/
	if (arr[i] != arr[end])
	{
		int tmp = arr[end];
		arr[end] = arr[i];
		arr[i] = tmp;
		print_array(arr, gl_size);
	}
	// else
	// {
	// 	printf(" **");
	// 	print_array(arr, gl_size);
	// }

	return i;
}
void qs(int *arr, int start, int end)
{
	if (start > end)
		return;
	int pivot_pos = partition(arr, start, end);

	qs(arr, start, pivot_pos - 1);
	qs(arr, pivot_pos + 1, end);
}

int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);
	gl_size = n;
	print_array(array, n);
	printf("--\n");
	qs(array, 0, n - 1);
	printf("\n");
	print_array(array, n);
	return (0);
}
