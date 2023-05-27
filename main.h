#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

int _printf_char(va_list args);
int _printf_str(va_list args);
int _printf_percent(va_list args);
int _putchar(char c);
int _printf(const char *format, ...);

#endif
