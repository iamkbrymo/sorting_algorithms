#include "sort.h"

/**
 * bubble_sort - A function that sorts array of integers in ascending order
 * @array: an array of integers
 * @size: size of the array
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	int change = 1;
	size_t i, temp, s = size;

	while (change)
	{
		change = 0;
		for (i = 1; i < s; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;

				change = 1;
				print_array(array, size);
			}
		}
		s--;
	}
}
