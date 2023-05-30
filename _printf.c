#include "main.h"
int handle_print(const char *fmt, int *ind, va_list ap, char buffer[],
		int flags, int width, int precision, int size);
void print_buffer(char buffer[], int *index);
/**
 * _printf - Printf homemade
 * @format: last variable
 * Return: Printed number of characters
 */
int _printf(const char *format, ...)
{
	int k, value = 0, count = 0;
	int width, flags, size, index = 0, precision;
	va_list ap;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	for (k = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			buffer[index++] = format[k];
			if (index == BUFF_SIZE)
				print_buffer(buffer, &index);
			/* write(1, &format[k], 1);*/
			count++;
		}
		else
		{
			flags = get_flags(format, &k);
			width = get_width(format, &k, ap);
			print_buffer(buffer, &index);
			precision = get_precision(format, &k, ap);
			size = get_size(format, &k);
			++k;
			value = handle_print(format, &k, ap, buffer, flags, width, precision, size);
			if (value == -1)
				return (-1);
			count += value;
		}
	}
	print_buffer(buffer, &index);
	va_end(ap);
	return (count);
}

/**
 * print_buffer - Prints contents of the buffer
 * @buffer: Array of chars
 * @index: Index that, represents the length.
 */
void print_buffer(char buffer[], int *index)
{
	if (*index > 0)
		write(1, &buffer[0], *index);

	*index = 0;
}

