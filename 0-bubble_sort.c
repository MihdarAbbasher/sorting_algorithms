#include "sort.h"

/**
 * bubble_sort - sort arr using bubble sort method
 * @array: arr to be sorted
 * @size: arr length
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, swap;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - 1; j++)
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swap = 1;
				print_array(array, size);
			}
		if (!swap)
			break;
	}
}

