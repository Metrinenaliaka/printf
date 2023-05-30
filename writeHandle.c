#include "main.h"
/**
 * handle_write_char - Function prints a string
 * size: specifier
 * @width: width (gets the width)
 * @flags:  active flags
 * @buffer: handles printing (this is a buffer array)
 * @precision: specifies the precision
 * @c: type of  characters
 * Return: chars printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int b = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		pad = '0';
	buffer[b++] = c;
	buffer[b] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (b = 0; b < width - 1; b++)
			buffer[BUFF_SIZE - b - 2] = pad;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - b - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - b - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
/**
 * write_number - Prints a string of numbers
 * @isNegative: arguments
 * @size: specifies the size
 * @width: width
 * @flags:  active flags
 * @buffer: handles printing (this is a buffer array)
 * @precision: specifies the precision
 * @index: types of characters
 * Return: chars printed
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
 * @ext_ch: an extra character
 * @len: length of the number
 * @pad: Pading
 * @width: width set
 * @prec: Precision
 * @buffer: Buffer size
 * @flags: Flags used
 * @index: where the number starts on the buffer
 * Return: the amount of printed character
 */
int write_num(int index, char buffer[],
	int flags, int width, int prec,
	int len, char pad, char ext_ch)
{
	int b, pad_start = 1;

	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0);
	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = pad = ' '; /* the width is normally shown with padding ' ' */
	if (prec > 0 && prec < len)
		pad = ' ';
	while (prec > len)
		buffer[--index] = '0', len++;
	if (ext_ch != 0)
		len++;
	if (width > len)
	{
		for (b = 1; b < width - len + 1; b++)
			buffer[b] = pad;
		buffer[b] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			if (ext_ch)
				buffer[--index] = ext_ch;
			return (write(1, &buffer[index], len) + write(1, &buffer[1], b - 1));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			if (ext_ch)
				buffer[--index] = ext_ch;
			return (write(1, &buffer[1], b - 1) + write(1, &buffer[index], len));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (ext_ch)
				buffer[--pad_start] = ext_ch;
			return (write(1, &buffer[pad_start], b - pad_start) +
				write(1, &buffer[index], len - (1 - pad_start)));
		}
	}
	if (ext_ch)
		buffer[--index] = ext_ch;
	return (write(1, &buffer[index], len));
}

/**
 * write_unsgnd - unsigned number
 * @isNegative: this indicates if the digit is negative
 * @size: specifier of the size
 * @width: specifier of the width
 * @precision: specifier of the precision
 * @flags: specifier of the flags
 * @buffer: characters array
 * @index: where the digit begins in the buffer
 * Return: written chars.
 */
int write_unsgnd(int isNegative, int index,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - index - 1, b = 0;
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
		for (b = 0; b < width - len; b++)
			buffer[b] = pad;

		buffer[b] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], len) + write(1, &buffer[0], b));
		}
		else
		{
			return (write(1, &buffer[0], b) + write(1, &buffer[index], len));
		}
	}

	return (write(1, &buffer[index], len));
}

/**
 * write_pointer - Writes memory address
 * @pad_begin: this is where padding should begin
 * @ext_ch: extra character
 * @len: number length
 * @flags:specifies the flags
 * @width: specifies the width
 * @pad: padding (the character representative of the process)
 * @len: number length
 * @index: this is where the number begins in buffer
 * @buffer: character array
 * Return: written chars
 */
int write_pointer(char buffer[], int index, int len,
	int width, int flags, char pad, char ext_c, int pad_begin)
{
	int b;

	if (width > len)
	{
		for (b = 3; b < width - len + 3; b++)
			buffer[b] = pad;
		buffer[b] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (ext_ch)
				buffer[--index] = ext_ch;
			return (write(1, &buffer[index], len) + write(1, &buffer[3], b - 3));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (ext_ch)
				buffer[--index] = ext_ch;
			return (write(1, &buffer[3], b - 3) + write(1, &buffer[index], len));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (ext_ch)
				buffer[--pad_begin] = ext_ch;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_begin], b - pad_begin) +
				write(1, &buffer[index], len - (1 - pad_begin) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (ext_ch)
		buffer[--index] = ext_ch;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}

