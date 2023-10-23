#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
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

int partition(int arr[], int left, int right)
{
	// Pivot element is the right most element
	int pivot = arr[right];
	printf("//pivot = %i \n", pivot);
	printf("\n***\n");

	// Index of smaller element
	int i = left;

	for (int j = left; j < right; j++)
	{
		// If current element is smaller than the pivot
		printf("%i <= %i = %i\n", arr[j], pivot, arr[j] <= pivot);
		if (arr[j] <= pivot)
		{
			// Swap current element with smaller element
			swap(&arr[i], &arr[j]);
			print_array(arr, 5);

			// Move to the next position for the smaller element
			i++;
		}
	}
	// Swap pivot element with the greater element at i
	swap(&arr[i], &arr[right]);
	print_array(arr, 5);
	printf("           ------        \n");

	// Return the position of the pivot

	return i;
}

// Function to perform quicksort
void quick_sort(int arr[], int left, int right)
{
	int k = left;
	printf("in: ");
	if (k < right)
	{
		while (k < right)
		{
			printf("%i ", arr[k]);
			k++;
		}
	}
	else
		printf(" left: %i right: %i ", left, right);

	// If left is less than right
	if (left < right)
	{

		// Partition the array around the pivot
		int pivotFinalRestingPosition = partition(arr, left, right);

		// Recursively sort the left and right subarrays
		quick_sort(arr, left, pivotFinalRestingPosition - 1);
		quick_sort(arr, pivotFinalRestingPosition + 1, right);
	}
	else
		printf("\n");
}

int main(void)
{
	int array[] = {5, 3, 4, 1, 2};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("--\n");
	quick_sort(array, 0, n - 1);
	printf("\n");
	print_array(array, n);
	return (0);
}
