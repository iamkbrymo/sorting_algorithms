#include "sort.h"

/**
 * selection_sort - A function that sorts an array using selection sort
 * @array: The array to sort
 * @size: Size of the array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t index, j, temp, kp;

	for (index = 0; index < size - 1; index++)
	{
		kp = index;
		for (j = index + 1; j < size; j++)
			if (array[j] < array[kp])
				kp = j;

		if (kp != index)
		{
			temp = array[index];
			array[index] = array[kp];
			array[kp] = temp;

			print_array(array, size);
		}
	}
}
