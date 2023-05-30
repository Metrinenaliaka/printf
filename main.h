#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFF_SIZE 1024
#define F_HASH 8
#define F_PLUS 2
#define F_MINUS 1
#define F_SPACE 16
#define F_ZERO 4
#define UNUSED(x) (void)(x)
/**
 * struct op - Structure op
 * @fmt: format.
 * @p: function related to struct
 */
typedef struct op
{
	char fmt;
	int (*p)(va_list, char[], int, int, int, int);
}op_t;
#define S_SHORT 1
#define S_LONG 2
int _printf(const char *format, ...);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
int is_printable(char);
long int convert_size_unsgnd(unsigned long int num, int size);
int print_string(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int print_char(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_int(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list args, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_pointer(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int get_width(const char *format, int *i, va_list ap);
int get_precision(const char *format, int *i, va_list ap);
int get_flags(const char *format, int *i);
int get_size(const char *format, int *i);
int print_rot13string(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_reverse(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int write_pointer(char buffer[], int index, int len, int width, int flags, char pad, char ext_c, int pad_start);
 int write_num(int index, char bff[], int flags, int width, int precision, int len, char pad, char ext_c);
int write_number(int is_positive, int index, char buffer[],
	int flags, int width, int precision, int size);
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_unsgnd(int isNegative, int index,
char buffer[], int flags, int width, int precision, int size);
#endif
