#include "function_pointers.h"

/**
 * print_name - prints a name using a function pointer
 * @name: string to print
 * @f: function used to print the name
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
