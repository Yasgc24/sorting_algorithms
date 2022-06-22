#include "sort.h"

/**
 * swap_int - function that swap two integers
 * @a: first integer to swap
 * @b: second integer to swap
 * Return: void
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - function that takes the last element as the
 * pivot, places the pivot element in its correct position
 * in the sorted array, and places all smaller ones to the
 * left of the pivot and all larger elements to the right of the pivot
 * @array: array of integers
 * @size: size of the array
 * @low: initial index of the array
 * @high: final index of the array
 * Return: void
 */

int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = (low - 1), j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap_int(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sortp - quicksort algorithm through recursion
 * @array: array of integers to be sorted
 * @size: size of the array
 * @low: starting index
 * @high: ending index
 */

void quick_sortp(int *array, size_t size, int low, int high)
{
	int idxpart;

	if (low < high)
	{
		idxpart = partition(array, size, low, high);

		quick_sortp(array, size, low, idxpart - 1);
		quick_sortp(array, size, idxpart + 1, high);
	}
}

/**
 * quick_sort - function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sortp(array, size, 0, size - 1);
}
