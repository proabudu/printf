#include "main.h"

/**
 * get_width - Get and process width specifier
 * @format: Format string
 * Return: Width specifier
 */
int get_width(const char *format)
{
    int width = 0;

    while (*format)
    {
        if (*format >= '1' && *format <= '9')
        {
            width = (*format - '0');
            format++;
            while (*format >= '0' && *format <= '9')
            {
                width = width * 10 + (*format - '0');
                format++;
            }
            break;
        }
        format++;
    }

    return width;
}

