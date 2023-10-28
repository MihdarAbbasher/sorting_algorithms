#include "sort.h"

/**
*swap - swap positions of two elements in an array
*@array: array
*@item1: 1st array element
*@item2: 2nd array element
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 *lomuto_partition - lomuto partition
 *@array: array
 *@low: low array element
 *@hi: hi array element
 *@size: size array
 *Return: return the position pi
 */
ssize_t lomuto_partition(int *array, ssize_t low, ssize_t hi, size_t size)
{
	int pivot = array[hi];
	ssize_t current, finder;

	current = low;
	for (finder = low; finder < hi; finder++)
	{
		if (array[finder] <= pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[hi])
	{
		swap(array, current, hi);
		print_array(array, size);
	}
	return (current);
}
/**
 *qs - quicksort algorithm recursively
 *@array: array
 *@low: low array element
 *@hi: hi array element
 *@size: array size
 */
void qs(int *array, ssize_t low, ssize_t hi, int size)
{
	ssize_t pi_position = 0;


	if (low < hi)
	{
		pi_position = lomuto_partition(array, low, hi, size);

		qs(array, low, pi_position - 1, size);
		qs(array, pi_position + 1, hi, size);
	}
}
/**
 *quick_sort - ckeck before quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
