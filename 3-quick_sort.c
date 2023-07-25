#include "sort.h"

int lomuto_partition(int *array, size_t size, int left, int right);
void swap_ints(int *a, int *b);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * lomuto_partition - Arranging the subset of an array.
 * @array: Array of integers.
 * @size: Size of the array.
 * @left: Starting index.
 * @right: Ending index
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

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
 * lomuto_sort - Sorts an array through recursion.
 * @array: Array of integers.
 * @size: Size of the array.
 * @left: Starting index.
 * @right: Ending index.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Prints the elements of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
