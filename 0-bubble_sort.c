#include "sort.h"

/**
 * swap_ints - Interchanges two integers.
 * @a: Integer one.
 * @b: Integer two.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Rearranges the array.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t n, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (n = 0; n < len - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				swap_ints(array + n, array + n + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
