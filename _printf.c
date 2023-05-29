#include "main.h"
/**
 * _printf - prints a string in a formatted way
 * @format: string to print
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0, temp = 0;
	va_list ap;
	int (*p)(va_list);

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
		{
			temp = write(1, &format[i], 1), count = count + temp, i++;
			continue;
		}
		if (format[i] == '%')
		{
			p = specifier(&format[i + 1]);
			if (p != NULL)
			{
				temp = p(ap), count += temp, i += 2;
				continue;
			}
			if (format[i + 1] == '\0')
				break;
			if (format[i + 1] != '\0')
			{
				temp = write(1, &format[i + 1], 1), count += temp, i += 2;
				continue;
			}
		}
	}
	return (count);
}
