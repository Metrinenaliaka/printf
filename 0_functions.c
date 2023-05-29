#include "main.h"
/**
 * print_char - Prints a charachter
 * @args: arguments
 * @buffer: rray handles print
 * @flags:  active flags
 * @width: Width of chars
 * @precision: specification for precision
 * @size: Size of specifier
 * Return: printed chars
 */
int print_char(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char x = va_arg(args, int);

	return (handle_write_char(x, buffer, flags, width, precision, size));
}
/**
 * print_string - Printing a string
 * @args: arguments list
 * @buffer: handles handle print
 * @flags: active flags
 * @width: width.
 * @precision: specification of precision
 * @size: specifier
 * Return: printed chars
 */
int print_string(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, j;
	char *str = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(width);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
		{
			str = "      ";
		}
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}
/**
 * print_percent - Prints percent
 * @args: List of arguments
 * @buffer: array to handle print
 * @flags: active flags
 * @width: get width of format.
 * @precision: specification
 * @size: specifier
 * Return: chars printed
 */
int print_percent(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(flags);
	UNUSED(width);
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_int - Prints integer
 * @args: Lists arguments
 * @buffer: array that handle print
 * @flags: active flags
 * @width: gets width of format.
 * @precision: specification
 * @size: specifier
 * Return: Number of chars printed
 */
int print_int(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	int isNegative = 0;
	long int m = va_arg(args, long int);
	unsigned long int nums;

	m = convert_size_number(m, size);

	if (m == 0)
		buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	nums = (unsigned long int)m;

	if (m < 0)
	{
		nums = (unsigned long int)((-1) * m);
		isNegative = 1;
	}

	while (nums > 0)
	{
		buffer[z--] = (nums % 10) + '0';
		nums /= 10;
	}

	z++;

	return (write_number(isNegative, z, buffer, flags, width, precision, size));
}
/**
 * print_binary - Function prints an unsigned number
 * @args: arguments
 * @buffer: to handle print
 * @flags: active flags
 * @width: width.
 * @precision: specification
 * @size: Specifier
 * Return: chars printed.
 */
int print_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int e, b, c, sum;
	unsigned int i[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(size);
	UNUSED(width);
	UNUSED(precision);

	e = va_arg(args, unsigned int);
	b = 2147483648; /* (2 ^ 31) */
	i[0] = e / b;
	for (c = 1; c < 32; c++)
	{
		b /= 2;
		i[c] = (e / b) % 2;
	}
	for (c = 0, sum = 0, count = 0; c < 32; c++)
	{
		sum += i[c];
		if (sum || c == 31)
		{
			char z = '0' + i[c];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
