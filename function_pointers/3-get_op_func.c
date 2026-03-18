#include <stddef.h>

#include "3-calc.h"

/**
 * get_op_func - selects the correct function for the operator
 * @s: operator passed as argument
 *
 * Return: pointer to the matching function, or NULL if no match
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op != NULL && (s[0] != ops[i].op[0] || s[1] != '\0'))
		i++;
	if (ops[i].op != NULL)
		return (ops[i].f);
	return (NULL);
}
