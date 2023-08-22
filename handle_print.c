#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_print - Handle the '%' character
 * @format: Format string
 * @args: Variable argument list
 * @count: Pointer to count of characters printed
 * Return: Number of characters printed
 */
int handle_print(const char *format, va_list args, int *count)
{
    int printed = 0;

    if (*format != '%')
        return 0; /* Not a valid print specifier */

    /* Handle the '%' character */
    write(1, format, 1);
    printed++;

    /* Update count and return printed */
    *count += printed;
    return printed;
}

