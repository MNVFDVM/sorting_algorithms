#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int m, j;

	for (m = array[0], j = 1; j < size; j++)
	{
		if (array[j] > m)
			m = array[j];
	}

	return (m);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *c, *s, m, j;

	if (array == NULL || size < 2)
		return;

	s = malloc(sizeof(int) * size);
	if (s == NULL)
		return;
	m = get_max(array, size);
	c = malloc(sizeof(int) * (m + 1));
	if (c == NULL)
	{
		free(s);
		return;
	}

	for (j = 0; j < (m + 1); j++)
		c[j] = 0;
	for (j = 0; j < (int)size; j++)
		c[array[j]] += 1;
	for (j = 0; j < (m + 1); j++)
		c[j] += c[j - 1];
	print_array(c, m + 1);

	for (j = 0; j < (int)size; j++)
	{
		s[c[array[j]] - 1] = array[j];
		c[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = s[j];

		free(s);
		free(c);
}
