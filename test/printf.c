#include "main.h"
/**
 * _printf - produces output according to a format.
 * @format: character string
 * Reurn: count of chars printed
 */
int _printf(const char *format, ...)
{
	va_list p;
	int count = 0;
	char x;
	const char *string;

	va_start(p, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				va_arg(p, int);
				write(1, &x, sizeof(x)), count++;
			}
			else if (*format == 's')
			{
				string = va_arg(p, const char *);
				while (*string != '\0')
					write(1, string, sizeof(char)), string++, count++;
			}
			else if (*format == '%')
			{
				x = '%';
				write(1, &x, sizeof(x)), count++;
			}
			else
			{
				x = '%', write(1, &x, sizeof(x));
				write(1, format, sizeof(char)), count += 2;
			}
		}
		else
			write(1, format, sizeof(char)), count++;
		format++;
	}
	va_end(p);
	return (count);
}
