#include <stdio.h>
#include <stdlib.h>

/**
 * is_number - checks if a string is made of digits only
 * @s: string to check
 *
 * Return: 1 if s is a number, 0 otherwise
 */
int is_number(char *s)
{
	int i;

	i = 0;
	if (s[i] == '\0')
		return (0);

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

/**
 * main - adds positive numbers
 * @argc: number of arguments
 * @argv: array of argument strings
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int i;
	int sum;

	sum = 0;
	i = 1;
	while (i < argc)
	{
		if (is_number(argv[i]) == 0)
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[i]);
		i++;
	}

	printf("%d\n", sum);
	return (0);
}
