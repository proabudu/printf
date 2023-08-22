#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include "conversion_utils.h"


/* Implementations for remaining conversion specifiers (o, x, X)... */

/**
 * handle_function2_conversion - Handle conversion specifiers in function2.c
 * @format: Format string
 * @args: Variable argument list
 * @count: Pointer to count of characters printed
 * Return: Number of characters printed
 */
int handle_function2_conversion(const char *format, va_list args, int *count)
{
    int printed = 0;

    if (format == NULL)
        return (-1);

    switch (*format)
    {
        case 'o':
            {
                unsigned int num = va_arg(args, unsigned int);
                printed += print_octal(num);
            }
            break;
        case 'x':
            {
                unsigned int num = va_arg(args, unsigned int);
                printed += print_hexadecimal(num, 0);
            }
            break;
        case 'X':
            {
                unsigned int num = va_arg(args, unsigned int);
                printed += print_hexadecimal(num, 1);
            }
            break;
        default:
            /* Handle unknown specifier */
            write(1, "%", 1);
            write(1, format - 1, 1);
            *count += 2;
            printed += 2;
            break;
    }

    /* Update count and return printed */
    *count += printed;
    return (printed);
}

