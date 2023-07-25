#include "sort.h"

/**
 * shell_sort - A function that sorts an array using Shell and Knuth sequence
 * @array: the array to sort
 * @size: the size of the array
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t kp = 1, index, j;
	int temp;

	if (size < 2)
		return;

	while (kp < size / 3)
		kp = kp * 3 + 1;

	while (kp > 0)
	{

		for (index = kp; index < size; index++)
		{
			temp = array[index];
			j = index;

			while (j > kp - 1 && array[j - kp] >= temp)
			{
				array[j] = array[j - kp];
				j = j - kp;
			}
			array[j] = temp;

		}
		kp = (kp - 1) / 3;
		print_array(array, size);
	}
}
