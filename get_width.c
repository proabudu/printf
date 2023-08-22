#include "main.h"

/**
 * get_width - Get and process field width
 * @format: Format string
 * @args: Variable argument list
 * Return: Field width
 */
int get_width(const char *format, va_list args)
{
    int width = -1; /* Default value for no field width specified */

    if (format == NULL)
        return (-1);

    while (*format)
    {
        if (*format == '*')
        {
            width = va_arg(args, int);
            format++; /* Move past '*' */
        }
        else if (*format >= '0' && *format <= '9')
        {
            width = 0;
            while (*format >= '0' && *format <= '9')
            {
                width = width * 10 + (*format - '0');
                format++;
            }
        }
        else
        {
            format++; /* Move to the next character in the format string */
        }
    }

    return width;
}

