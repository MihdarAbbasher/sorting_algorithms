#include "sort.h"

/**
 * selection_sort - sort using selection
 * @array: arr to be sorted
 * @size: arr length
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t smallest_idx, i, j;
	int tmp;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		smallest_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[smallest_idx] > array[j])
				smallest_idx = j;
		}
		if (smallest_idx != i)
		{
			tmp = array[i];
			array[i] = array[smallest_idx];
			array[smallest_idx] = tmp;
			print_array(array, size);
		}
	}
}

