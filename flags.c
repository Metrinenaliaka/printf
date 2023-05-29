#include "main.h"

/**
 * get_flags - active flags
 * @format: Formatted string
 * @i: parameter.
 * Return: Flags to be printed
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int k, cur_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		for (k = 0; FLAGS_CH[k] != '\0'; k++)
			if (format[cur_i] == FLAGS_CH[k])
			{
				flags |= FLAGS_ARR[k];
				break;
			}
		if (FLAGS_CH[k] == 0)
			break;
	}

	*i = cur_i - 1;

	return (flags);
}

