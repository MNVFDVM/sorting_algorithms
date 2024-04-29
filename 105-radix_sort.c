#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

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
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int c[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t j;

	for (j = 0; j < size; j++)
		c[(array[j] / sig) % 10] += 1;

	for (j = 0; j < 10; j++)
		c[j] += c[j - 1];

	for (j = size - 1; (int)j >= 0; j--)
	{
		buff[c[(array[j] / sig) % 10] - 1] = array[j];
		c[(array[j] / sig) % 10] -= 1;
	}

	for (j = 0; j < size; j++)
		array[j] = buff[j];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int m, s, *b;
	
	if (array == NULL || size < 2)
		return;

	b = malloc(sizeof(int) * size);
	if (b == NULL)
		return;

	m = get_max(array, size);
	for (s = 1; m / s > 0; s *= 10)
	{
		radix_counting_sort(array, size, s, b);
		print_array(array, size);
	}

	free(b);
}
