#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);

int handle_conversion(const char *format, va_list args);
int handle_custom_conversion(const char *format, va_list args);
int handle_function2_conversion(const char *format, va_list args, int *count);

int get_flags(const char *format);
int get_precision(const char *format, va_list args);
int get_size(const char *format);

int write_handlers(const char *str, int len);

#endif /* MAIN_H */

