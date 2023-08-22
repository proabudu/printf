#include <stdarg.h>
#include "main.h"

/**
 * get_width - Get and process width specifier
 * @format: Format string
 * @args: Variable argument list
 * Return: Width specifier
 */
int get_width(const char *format, va_list args)
{
    int width = 0;

    while (*format)
    {
        if (*format >= '1' && *format <= '9')
        {
            while (*format >= '0' && *format <= '9')
            {
                width = width * 10 + (*format - '0');
                format++;
            }
            return width;
        }
        format++;
    }

    return width;
}

