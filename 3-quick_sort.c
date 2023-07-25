#include "sort.h"

/**
 * partition - A funtion that partitions
 * @array: The array to partition
 * @low: shows the low
 * @high: shows the high
 * @size: size of the array
 * Return: return the sorted
 */

size_t partition(int **array, size_t low, size_t high, size_t size)
{
	size_t index, j;
	int temp, kp;

	kp = (*array)[high];
	index  = low - 1;
	for (j = low; j < high; j++)
	{
		if ((*array)[j] <= kp)
		{
			index++;
			temp = (*array)[index];
			(*array)[index] = (*array)[j];
			(*array)[j] = temp;
			if ((*array)[index] !=  (*array)[j])
				print_array(*array, size);
		}
	}

	temp =  (*array)[index + 1];
	(*array)[index + 1] = (*array)[high];
	(*array)[high] = temp;
	if ((*array)[index + 1] !=  (*array)[high])
		print_array(*array, size);
	return (index + 1);
}

/**
 * quick - A quick sort function
 * @array: Array to sort
 * @low: showing low
 * @high: showing high
 * @size: size of the array
 * Return: The sorted array
 */

void quick(int **array, size_t low, size_t high, size_t size)
{
	size_t par;

	if (low < high)
	{
		par = partition(array, low, high, size);

		if (par != 0)
			quick(array, low, (par - 1), size);
		if (par < size - 1)
			quick(array, (par + 1), high, size);
	}
}

/**
 * quick_sort - A function that sorts an array using a quick sort method
 * @array: The array to sort
 * @size: The size of the array
 * Return: The sorted array
 */

void quick_sort(int *array, size_t size)
{
	if (size > 1)
		quick(&array, 0, (size - 1), size);
}
