#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to scan
 * @accept: accepted bytes
 *
 * Return: number of bytes in initial segment of s made only of accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i;
	unsigned int j;
	unsigned int match;

	i = 0;
	while (s[i] != '\0')
	{
		match = 0;
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				match = 1;
				break;
			}
			j++;
		}

		if (match == 0)
			break;

		i++;
	}

	return (i);
}
