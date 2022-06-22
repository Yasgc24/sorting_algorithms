#include "sort.h"

/**
 * swap_int - funtcion that swap two integers
 * @array: array
 * @size: size of the array
 * @x: first integer to swap
 * @y: second integer to swap
 * Return: void
 */

void swap_int(int *array, size_t size, int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
	print_array(array, size);
}

/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_pos;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_pos])
			{
				min_pos = j;
			}
		}
		if (min_pos != i)
		{
			swap_int(array, size, &array[min_pos], &array[i]);
		}
	}
}
