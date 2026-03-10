#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated duplicate of a string
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string, or NULL on failure
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i;
	unsigned int len;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len] != '\0')
		len++;

	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);

	i = 0;
	while (i <= len)
	{
		dup[i] = str[i];
		i++;
	}

	return (dup);
}
