#include "main.h"
/**
 * p_cent - prints character % to stdout
 * @ap: variadic parameter
 * Return: number of characters printed
 */
int p_cent(va_list ap)
{
	(void)ap;

	write(1, "%", 1);

	return (1);
}
/**
 * p_char - prints a character to stdout
 * @ap: variadic parameter
 * Return: number of characters printed
 */
int p_char(va_list ap)
{
	char x = (char)va_arg(ap, int);
	int count = 0;

	if (x)
	{
		count = write(1, &x, 1);
		return (count);
	}
	return (0);
}
/**
 * p_str - prints a variadic string each per time to stdout
 * @ap: variadic parameter
 * Return: number of characters printed
 */
int p_str(va_list ap)
{
	char *string = va_arg(ap, char *);
	int count = 0;

	if (string)
	{
		while (*string != '\0')
		{
			count = write(1, string, 1);
			string++;
		}
		return (count);

	}
	return (0);
}
