#include <stdio.h>

/**
 * main - Entry point
 *
 * Calculator uses double for consistent decimal behavior.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice;
	double a;
	double b;
	double result;

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

		printf("A: ");
		if (scanf("%lf", &a) != 1)
			return (0);

		printf("B: ");
		if (scanf("%lf", &b) != 1)
			return (0);

		if (choice == 1)
			result = a + b;
		else if (choice == 2)
			result = a - b;
		else if (choice == 3)
			result = a * b;
		else if (choice == 4)
		{
			if (b == 0)
			{
				printf("Error: division by zero\n");
				continue;
			}
			result = a / b;
		}

		printf("Result: %g\n", result);
	}

	return (0);
}
