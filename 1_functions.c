#include "main.h"
/**
 *print_octal - Print unsigned number in octal
 * @args: arguments
 * @buffer: handle print
 * @flags: active flags
 * @width: width
 * @precision: specification
 * @size: Specifier
 * Return: chars printed
 */
int print_octal(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{

	int k = BUFF_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);
	unsigned long int initial_num = number;

	UNUSED(width);
	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buffer[k--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && initial_num != 0)
		buffer[k--] = '0';

	k++;
	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}
/**
 * print_unsigned - function prints unsigned number
 * @args: arguments
 * @buffer: handle print
 * @flags:  active flags
 * @width: width
 * @precision: specification
 * @size: Specifier
 * Return: chars printed.
 */
int print_unsigned(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int nums = va_arg(args, unsigned long int);

	nums = convert_size_unsgnd(nums, size);

	if (nums == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (nums > 0)
	{
		buffer[j--] = (nums % 10) + '0';
		nums /= 10;
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}
/**
 * print_hexa_upper - Prints upper hexadecimal notation
 * @args: arguments
 * @buffer: handle print
 * @flags:  active flags
 * @width: width
 * @precision: specification
 * @size: Specifier
 * Return: chars printed
 */
int print_hexa_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/**
 * print_hexadecimal - number in hexadecimal notation
 * @args: arguments
 * @buffer: handle print
 * @flags:  active flags
 * @width: width
 * @precision: specification
 * @size: Specifier
 * Return: chars printed
 */
int print_hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/**
 * print_hexa - hexadecimal number in lower or upper
 * @args: arguments
 * @map_to: Array that maps the number to
 * @buffer: handle print
 * @flags:  active flags
 * @flag_ch: active flags
 * @width: width
 * @precision: specification
 * @size: Specifier
 * @size: specification
 * Return: chars printed
 */
int print_hexa(va_list args, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	unsigned long int numbers = va_arg(args, unsigned long int);
	unsigned long int init_nums = numbers;

	UNUSED(width);
	numbers = convert_size_unsgnd(numbers, size);
	if (numbers == 0)
		buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numbers > 0)
	{
		buffer[z--] = map_to[numbers % 16];
		numbers /= 16;
	}

	if (flags & F_HASH && init_nums != 0)
	{
		buffer[z--] = flag_ch;
		buffer[z--] = '0';
	}

	z++;

	return (write_unsgnd(0, z, buffer, flags, width, precision, size));
}
