#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *m;
	size_t h, k;

	if (array == NULL || size < 2)
		return;

	for (h = 0; h < size - 1; h++)
	{
		m = array + h;
		for (k = h + 1; k < size; k++)
			m = (array[k] < *m) ? (array + k) : m;

		if ((array + h) != m)
		{
			swap_ints(array + h, m);
			print_array(array, size);
		}
	}
}
