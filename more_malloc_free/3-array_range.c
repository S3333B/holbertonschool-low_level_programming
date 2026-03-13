#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: minimum value
 * @max: maximum value
 *
 * Return: pointer to the new array, or NULL on failure
 */
int *array_range(int min, int max)
{
	int *array;
	int value;
	size_t size, i;

	if (min > max)
		return (NULL);

	size = (size_t)((long)max - (long)min + 1);
	if (size > ((size_t)-1) / sizeof(int))
		return (NULL);

	array = malloc(size * sizeof(int));
	if (array == NULL)
		return (NULL);

	value = min;
	for (i = 0; i < size; i++)
	{
		array[i] = value;
		if (i + 1 < size)
			value++;
	}

	return (array);
}
