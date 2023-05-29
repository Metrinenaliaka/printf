#include "main.h"
#include <stdio.h>
/**
 *count_digits - counts number of digits
 *@n: didgit
 *Return: numbe of digits
 */
int count_digits(int n)
{
	if (n/10 == 0)
		return 1;
	return 1 + count_digits(n / 10);
}
/**
 * _printf - produces output according to format
 * @format: character string
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int num, divisor = 1, count = 0, num_digits, i;
	char ch;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				num = va_arg(ap, int);
				if (num < 0)
				{
					ch = '-';
					write(1, &ch, sizeof(ch)), count++, num = -num;
				}
				num_digits = count_digits(num);
				for (i = 1; i < num_digits; i++)
				{
					divisor *= 10;
				}
				while (divisor > 0)
				{
					ch = '0' + (num / divisor);
					write(1, &ch, sizeof(ch)), count++;
					num %= divisor, divisor /= 10;
				}
			}
			else if (*format == '%')
			{
				ch = '%';
				write(1, &ch, sizeof(ch)), count++;
			}
			else
			{
				ch = '%';
				write(1, &ch, sizeof(ch));
				write(1, format, sizeof(char)), count += 2;
			}
		}
		else
		{
			write(1, format, sizeof(char)), count++;
		}
		format++;
	}
	va_end(ap);
	return count;
}
