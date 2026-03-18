#include <stdio.h>
#include "variadic_functions.h"

/**
 * struct print_type - maps a format specifier to a print function
 * @type: format character
 * @print: function that prints the matching argument
 */
typedef struct print_type
{
	char type;
	void (*print)(va_list *args, char **separator);
} print_type_t;

/**
 * print_char - prints a character argument
 * @args: variadic argument list
 * @separator: current separator string
 *
 * Return: nothing
 */
static void print_char(va_list *args, char **separator)
{
	printf("%s%c", *separator, va_arg(*args, int));
	*separator = ", ";
}

/**
 * print_int - prints an integer argument
 * @args: variadic argument list
 * @separator: current separator string
 *
 * Return: nothing
 */
static void print_int(va_list *args, char **separator)
{
	printf("%s%d", *separator, va_arg(*args, int));
	*separator = ", ";
}

/**
 * print_float - prints a float argument
 * @args: variadic argument list
 * @separator: current separator string
 *
 * Return: nothing
 */
static void print_float(va_list *args, char **separator)
{
	printf("%s%f", *separator, va_arg(*args, double));
	*separator = ", ";
}

/**
 * print_string - prints a string argument
 * @args: variadic argument list
 * @separator: current separator string
 *
 * Return: nothing
 */
static void print_string(va_list *args, char **separator)
{
	char *str;

	str = va_arg(*args, char *);
	switch (!!str)
	{
		case 0:
			str = "(nil)";
			break;
	}
	printf("%s%s", *separator, str);
	*separator = ", ";
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	int i;
	int j;
	char *separator;
	va_list args;
	print_type_t types[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};

	va_start(args, format);
	i = 0;
	separator = "";
	while (format != NULL && format[i] != '\0')
	{
		j = 0;
		while (types[j].type != '\0')
		{
			if (format[i] == types[j].type)
			{
				types[j].print(&args, &separator);
				break;
			}
			j++;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
