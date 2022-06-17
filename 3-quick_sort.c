#include "sort.h"

/**
 * swap_int - function that swap two integers
 * @array: array of elements
 * @size: size of the array
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
 * @brief 
 * 
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
    return(i + 1);
}

/**
 * @brief 
 * 
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
 * @brief 
 * 
 */

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    
    quick_sortp(array, size, 0, size - 1);
}