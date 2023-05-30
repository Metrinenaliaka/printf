#include "main.h"
/**
 * handle_write_char - Function prints a string
 * @c: chars.
 * @buffer: handle print
 * @flags:  active flags.
 * @width: width.
 * @precision: precision
 * @size: Specifier
 * Return: chars printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		pad = '0';
	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = pad;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
/**
 * write_number - Prints a string of numbers
 * @isNegative: arguments
 * @index: chars.
 * @buffer: handle print
 * @flags:  active flags
 * @width: width.
 * @precision: precision
 * @size: Specifier
 * Return: chars printed.
 */
int write_number(int isNegative, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - index - 1;
	char pad = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (isNegative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';
	return (write_num(index, buffer, flags, width, precision,
		len, pad, extra_ch));
}

/**
 * write_num - Writes number using a bufffer
 * @index: Index where the number starts on the buffer
 * @buffer: Buffer size
 * @flags: Flags used
 * @width: width set
 * @prec: Precision
 * @len: length
 * @pad: Pading
 * @ext_c: char
 * Return: printed chars.
 */
int write_num(int index, char buffer[],
	int flags, int width, int prec,
	int len, char pad, char ext_c)
{
	int i, pad_start = 1;

	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0);
	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = pad = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < len)
		pad = ' ';
	while (prec > len)
		buffer[--index] = '0', len++;
	if (ext_c != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			if (ext_c)
				buffer[--index] = ext_c;
			return (write(1, &buffer[index], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			if (ext_c)
				buffer[--index] = ext_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], len));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (ext_c)
				buffer[--pad_start] = ext_c;
			return (write(1, &buffer[pad_start], i - pad_start) +
				write(1, &buffer[index], len - (1 - pad_start)));
		}
	}
	if (ext_c)
		buffer[--index] = ext_c;
	return (write(1, &buffer[index], len));
}

/**
 * write_unsgnd - unsigned number
 * @isNegative: num is negative
 * @index: number starts in the buffer
 * @buffer: chars
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: written chars.
 */
int write_unsgnd(int isNegative, int index,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - index - 1, i = 0;
	char pad = ' ';

	UNUSED(isNegative);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);
	if (precision > 0 && precision < len)
		pad = ' ';

	while (precision > len)
	{
		buffer[--index] = '0';
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = pad;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], len) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[index], len));
		}
	}

	return (write(1, &buffer[index], len));
}

/**
 * write_pointer - Writes memory address
 * @buffer: chars
 * @index: number starts in the buffer
 * @len: number length
 * @width: Width
 * @flags: Flags
 * @pad: padding
 * @ext_c: extra char
 * @pad_start: padding should start
 * Return: written chars.
 */
int write_pointer(char buffer[], int index, int len,
	int width, int flags, char pad, char ext_c, int pad_start)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (ext_c)
				buffer[--index] = ext_c;
			return (write(1, &buffer[index], len) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (ext_c)
				buffer[--index] = ext_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], len));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (ext_c)
				buffer[--pad_start] = ext_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_start], i - pad_start) +
				write(1, &buffer[index], len - (1 - pad_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (ext_c)
		buffer[--index] = ext_c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}

