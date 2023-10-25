// C program for Merge Sort
#include <stdio.h>
#include <stdlib.h>
// Function to print an array
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int start, int end)
{
	int mid = (start + end) / 2;
	int n1 = mid - start + 1;
	int n2 = end - mid;
	int *left = (int *)malloc(n1 * sizeof(int));
	int *right = (int *)malloc(n2 * sizeof(int));
	int i = 0, j = 0, k = start;

	printArray(arr, end);
	printf("n1 = %i ,n2 = %i, mid = %i\n", n1, n2, mid);
	for (i = 0; i < n1; i++)
		left[i] = arr[start + i];

	for (; j < n2; j++)
		right[j] = arr[mid + 1 + j];

	// printArray(left, mid);

	printArray(right, end - mid);

	for (j = 0, i = 0; i < n1 && j < n2;)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = left[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
	free(left);
	free(right);
}
void _merge_sort(int *arr, int start, int end)
{

	int m = start + (end - start) / 2;

	if (start >= end)
		return;

	_merge_sort(arr, start, m);
	_merge_sort(arr, m + 1, end);

	merge(arr, start, end);
}
void merge_sort(int *array, size_t size)
{

	_merge_sort(array, 0, (int)size);
}

// Driver code
int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);
	printf("arr_size %i \n", arr_size) - 1;
	merge_sort(arr, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}
