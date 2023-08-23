#include "main.h"

/**
 * get_precision - Get and process precision
 * @format: Format string
 * @args: Variable argument list
 * Return: Precision
 */
int get_precision(const char *format, va_list args)
{
    int precision = -1; /*  Default value for no precision specifie */

    if (format == NULL)
        return (-1);

/*  Find the dot ('.') that indicates the start of precision specifier */
    while (*format && *format != '.')
    {
        format++;
    }

    if (*format == '.')
    {
/*  Precision specifier found, move to the next character */
        format++;

/*  Parse the precision value from the format string */
        if (*format == '*')
        {
/*  Handle '*' (variable precision) case */
            precision = va_arg(args, int);
            format++; /*  Move past '*' */
        }
        else
        {
/*  Parse numeric precision value */
            precision = 0;
            while (*format >= '0' && *format <= '9')
            {
                precision = precision * 10 + (*format - '0');
                format++;
            }
        }
    }

    return precision;
}

