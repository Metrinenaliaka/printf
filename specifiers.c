#include "main.h"

/**
 * specifier - check that character is a valid specifier and
 * assigns an appropriate fucntion for its printing.
 * @format: the specifier (char*)
 * Return: pointer to function, if successful
 * NULL pointer if not successful
 */
int (*specifier(const char *format))(va_list)
{
	int j;

	op_t array[] = {
		{"c", p_char},
		{"s", p_str},
		{"%", p_cent},
		{NULL, NULL}};

	for (j = 0; array[j].t != NULL; j++)
	{
		if (*(array[j].t) == *format)
		{
			return (array[j].p);
		}
	}

	return (NULL);
}
