#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to scan
 * @accept: bytes to match
 *
 * Return: pointer to first matching byte in s, or NULL
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s != '\0')
	{
		i = 0;
		while (accept[i] != '\0')
		{
			if (*s == accept[i])
				return (s);
			i++;
		}
		s++;
	}

	return ('\0');
}
