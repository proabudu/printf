#include "main.h"

/**
 * print_binary - Print an unsigned integer in binary
 * @n: Unsigned integer to print
 * Return: Number of characters printed
 */
int print_binary(unsigned int n)
{
    char binary[32];
    int count = 0, i = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    while (n > 0)
    {
        binary[i] = (n % 2) + '0';
        n /= 2;
        i++;
    }

    while (i > 0)
    {
        write(1, &binary[i - 1], 1);
        count++;
        i--;
    }

    return (count);
}

/**
 * print_hex_non_printable - Print non-printable characters in hexadecimal
 * @c: Character to print
 * Return: Number of characters printed
 */
int print_hex_non_printable(char c)
{
    char hex[] = "0123456789ABCDEF";
    int count = 0;

    write(1, "\\x", 2);
    write(1, &hex[(c >> 4) & 0x0F], 1);
    write(1, &hex[c & 0x0F], 1);
    count += 4;

    return (count);
}

/**
 * handle_custom_conversion - Handle custom conversion specifiers
 * @format: Format string
 * @args: Variable argument list
 * Return: Number of characters printed
 */
int handle_custom_conversion(const char *format, va_list args)
{
    int count = 0;

    if (format == NULL)
        return (-1);

    switch (*format)
    {
        case 'b':
            count += print_binary(va_arg(args, unsigned int));
            break;
        case 'S':
            {
                char *str = va_arg(args, char *);
                int i = 0;

                if (str == NULL)
                    return (-1);

                while (str[i])
                {
                    if (str[i] < 32 || str[i] >= 127)
                        count += print_hex_non_printable(str[i]);
                    else
                    {
                        write(1, &str[i], 1);
                        count++;
                    }
                    i++;
                }
            }
            break;
/* Add cases for other custom conversion specifiers...
        default: */

            write(1, format - 1, 1);
            write(1, format, 1);
            count += 2;
            break;
    }

    return (count);
}

