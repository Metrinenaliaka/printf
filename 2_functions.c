#include "main.h"
/**
 * print_rot13string - string in rot13.
 * @args: arguments
 * @buffer: handle print
 * @flags:  active flags
 * @width: width
 * @precision: specification
 * @size: specifier
 * Return: chars printed
 */
int print_rot13string(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char y;
	char *string;
	unsigned int a, b;
	int count = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(args, char *);
	UNUSED(size);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(buffer);

	if (string == NULL)
		string = "(AHYY)";
	for (a = 0; string[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (input[j] == string[a])
			{
				y = output[b];
				write(1, &y, 1);
				count++;
				break;
			}
		}
		if (!input[b])
		{
			y = string[a];
			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}
/**
 * print_pointer - function prints value of a pointer variable
 * @args: arguments
 * @buffer: handle print
 * @flags:  active flags
 * @width: width
 * @precision: specification
 * @size: specifier
 * Return: chars printed.
 */
int print_pointer(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char ext_c = 0, pad = ' ';
	int index = BUFF_SIZE - 2, len = 2, pad_start = 1; /* length=2, for '0x' */
	unsigned long num_addres;
	char map_to[] = "0123456789abcdef";
	void *addres = va_arg(args, void *);

	UNUSED(size);
	UNUSED(width);

	if (addres == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addres = (unsigned long)addres;
	while (num_addres > 0)
	{
		buffer[index--] = map_to[num_addres % 16];
		num_addres /= 16;
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (flags & F_PLUS)
		ext_c = '+', len++;
	else if (flags & F_SPACE)
		ext_c = ' ', len++;

	index++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, index, len,
		width, flags, padd, ext_c, pad_start));
}
/**
 * print_non_printable - ascii codes in hexa of non printable chars
 * @args: arguments
 * @buffer: handle print
 * @flags:  active flags
 * @width: width
 * @precision: specification
 * @size: Specifier
 * Return: chars printed
 */
int print_non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0, offsets = 0;
	char *strs = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);

	if (strs == NULL)
		return (write(1, "(null)", 6));

	while (strs[j] != '\0')
	{
		if (is_printable(strs[j]))
			buffer[j + offsets] = strs[j];
		else
			offsets += append_hexa_code(strs[j], buffer, j + offsets);
		j++;
	}
	buffer[j + offsets] = '\0';

	return (write(1, buffer, j + offsets));
}
/**
 * print_reverse - reverse string.
 * @args: arguments
 * @buffer: handle print
 * @flags:  active flags
 * @width: width
 * @precision: specification
 * @size: Specifier
 * Return: chars printed
 */

int print_reverse(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char *st;
	int k, count = 0;

	UNUSED(width);
	UNUSED(flags);
	UNUSED(buffer);
	UNUSED(size);

	st = va_arg(args, char *);

	if (st == NULL)
	{
		UNUSED(precision);
		st = ")Null(";
	}
	for (k = 0; st[k]; k++)
		;
	for (k = k - 1; k >= 0; k--)
	{
		char z = st[k];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

