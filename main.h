#ifndef MAIN_H
#define MAIN_H

#define FLAG_PLUS   (1 << 0)
#define FLAG_SPACE  (1 << 1)
#define FLAG_HASH   (1 << 2)

#define LENGTH_NONE 0
#define LENGTH_HH   1
#define LENGTH_H    2
#define LENGTH_LL   3
#define LENGTH_L    4

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

