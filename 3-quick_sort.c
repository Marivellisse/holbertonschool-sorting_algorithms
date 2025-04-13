#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: The array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Full size of array (for print_array)
 * Return: Final pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j && array[i] != array[j])
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high && array[i] != array[high])
	{
		swap_ints(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort_recursive - Recursive Quick Sort function
 * @array: The array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quicksort_recursive(array, low, pi - 1, size);
		quicksort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Entry point for Quick Sort
 * @array: The array to sort
 * @size: Number of elements
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort_recursive(array, 0, size - 1, size);
}

