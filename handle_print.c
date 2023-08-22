#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_print - Handle the print conversion specifier
 * @format: Format string
 * @args: Variable argument list
 * @count: Pointer to count of characters printed
 * Return: Number of characters printed
 */
int handle_print(const char *format, va_list args, int *count)
{
    int printed = 0;

    if (format == NULL)
        return (-1);

    switch (*format)
    {
        case 'c':
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                printed++;
            }
            break;
        case 's':
            {
                char *str = va_arg(args, char *);
                if (!str)
                    str = "(null)";
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    printed++;
                }
            }
            break;
        case '%':
            write(1, "%", 1);
            printed++;
            break;
        default:
            write(1, "%", 1);
            write(1, format - 1, 1);
            *count += 2;
            printed += 2;
            break;
    }

    /* Update count and return printed */
    *count += printed;
    return printed;
}

