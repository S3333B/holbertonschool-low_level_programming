#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice;
	int a;
	int b;
	int result;

	while (1)
	{
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		if (scanf("%d", &choice) != 1)
			return (0);

		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}

		if (choice < 0 || choice > 4)
		{
			printf("Invalid choice\n");
			continue;
		}

		if (choice == 1)
		{
			printf("A: ");
			if (scanf("%d", &a) != 1)
				return (0);

			printf("B: ");
			if (scanf("%d", &b) != 1)
				return (0);

			result = a + b;
			printf("Result: %d\n", result);
		}
	}

	return (0);
}
