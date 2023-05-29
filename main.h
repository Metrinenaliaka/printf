#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define F_HASH 8
#define F_SPACE 16
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define UNUSED(x) (void)(x)
/**
 * struct op - Struct op
 * @fmt: The format.
 * @p: The function associated.
 */
typedef struct op
{
	char fmt;
	int (*p)(va_list, char[], int, int, int, int);
}op_t;

#define S_SHORT 1
#define S_LONG 2
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int _printf(const char *format, ...);
#endif
