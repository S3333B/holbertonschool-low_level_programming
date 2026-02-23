#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	printf("The size of a char: %zu\n", sizeof(char));
	printf("The size of a long int: %zu\n", sizeof(long int));
	printf("The size of a long long int: %zu\n", sizeof(long long int));
	printf("The size of a float: %zu\n", sizeof(float));
	return (0);
}
