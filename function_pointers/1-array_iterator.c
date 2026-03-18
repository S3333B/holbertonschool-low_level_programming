#include "function_pointers.h"

/**
 * array_iterator - executes a function on each element of an array
 * @array: array to iterate on
 * @size: number of elements in the array
 * @action: function to execute on each element
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array && action)
	{
		for (i = 0; i < size; i++)
			action(array[i]);
	}
}
