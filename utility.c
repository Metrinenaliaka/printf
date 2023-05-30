#include "main.h"

/**
 * is_printable - checks if a character can be printed
 * @a: character checked
 * Return: 1 if chracter is printable and 0 otherwise
 */
int is_printable(char a)
{
	if (a >= 32 && a < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - attaches the ASCII values in hexa code to the buffer
 * @buffer: Array.
 * @k: Index where attaching begins
 * @ascii_code: ASCII value of characters
 * Return: 3
 */
int append_hexa_code(char ascii_code, char buffer[], int k)
{
	char map_to[] = "0123456789ABCDEF";
	/* Normally, the hexa format code has a length of 2 digits */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[k++] = '\\';
	buffer[k++] = 'x';

	buffer[k++] = map_to[ascii_code / 16];
	buffer[k] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - checks if a character is a digit
 * @a: Character checked
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}
/**
 * convert_size_number - Casts a number to the indicated size
 * @num: Number casted
 * @size: digit showing what type to be casted
 * Return: value of num which is casted
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((short)num);
	}
	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to a defined size
 * @num: casted number
 * @size: digit showing what type to be casted
 * Return: value of num which is casted
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)num);
	}
	return ((unsigned int)num);
}

