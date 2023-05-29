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
void print_buffer(char buffer[], int *buff_ind);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int _printf(const char *format, ...);
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

#endif
