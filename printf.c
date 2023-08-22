<<<<<<< HEAD
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
=======
printf.c

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "printf.h"
>>>>>>> c9307921454aa830c2afab2bc873720d9a43e6ed

/**
* _printf - prints output according to a format.
* @format: character string.
*
* Return: the number of characters printed (excluding the null byte used to end output to strings)
*/
int _printf(const char *format, ...)
{
int i = 0, count = 0;
va_list args;
va_start(args, format);
while (format && format[i])
{
if (format[i] == '%')
{
i++;
if (format[i] == 'c')
<<<<<<< HEAD
count += write(1, &va_arg(args, int), 1);
else if (format[i] == 's')
count += write(1, va_arg(args, char *), strlen(va_arg(args, char *)));
else if (format[i] == '%')
count += write(1, "%", 1);
}
else
count += write(1, &format[i], 1);
i++;
}
va_end(args);
return (count);
=======
{
char c = (char) va_arg(args, int);
count += write(1, &c, 1);
}
else if (format[i] == 's')
{
char *s = va_arg(args, char *);
count += write(1, s, strlen(s));
}
else if (format[i] == '%')
{
count += write(1, "%", 1);
}
}
else
{
count += write(1, &format[i], 1);
}
i++;
}
va_end(args);
return count;
>>>>>>> c9307921454aa830c2afab2bc873720d9a43e6ed
}

