#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: pointer to the string to print
 */
void puts_half(char *str)
{
	int len;
	int half;
	int start;

	len = 0;
	while (str[len] != '\0')
		len++;

	half = len / 2;
	if (len % 2 != 0)
		half = (len + 1) / 2;

	start = len - half;

	while (str[start] != '\0')
	{
		_putchar(str[start]);
		start++;
	}
	_putchar('\n');
}
