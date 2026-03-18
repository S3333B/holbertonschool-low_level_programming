#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: array to search in
 * @size: number of elements in the array
 * @cmp: function used to compare values
 *
 * Return: index of the first matching element, or -1 on failure/no match
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (!array || size <= 0 || !cmp)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}

	return (-1);
}
