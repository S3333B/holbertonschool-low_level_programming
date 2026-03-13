#include "main.h"
#include <limits.h>
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array
 * @nmemb: number of elements
 * @size: size of each element
 *
 * Return: pointer to allocated memory, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i, total_size;
	char *array;

	if (nmemb == 0 || size == 0)
		return (NULL);

	if (nmemb > UINT_MAX / size)
		return (NULL);

	total_size = nmemb * size;
	array = malloc(total_size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < total_size; i++)
		array[i] = 0;

	return (array);
}
