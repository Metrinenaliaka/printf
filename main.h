#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int (specifier(const char *))(va_list);

/**
 * struct op - struct for specifier to printer
 * @t: character to compare
 * @p: function to handle printing
 */
typedef struct op
{
	char *t;
	int (*p)(va_list);
} op_t;

int p_char(va_list);
int p_str(va_list);
int p_cent(va_list);

#endif
