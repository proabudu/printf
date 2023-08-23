#include "main.h"

/**
 * print_number - Helper function to print an integer
 * @n: Integer to print
 */
void print_number(int n)
{
    char digit;
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n / 10 != 0)
        print_number(n / 10);
    digit = (n % 10) + '0';
    write(1, &digit, 1);
}

/**
 * _print_d - Print a decimal integer
 * @args: Variable argument list
 * Return: Number of characters printed
 */
int _print_d(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;

    print_number(num);
    while (num / 10)
    {
        num /= 10;
        count++;
    }
    return (count + 1);
}

/**
 * _print_u - Print an unsigned decimal integer
 * @args: Variable argument list
 * Return: Number of characters printed
 */
int _print_u(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    print_number(num);
    while (num / 10)
    {
        num /= 10;
        count++;
    }
    return (count + 1);
}

/*  Similar implementations for other conversion specifiers (o, x, X)... */

/**
 * handle_conversion - Handle different conversion specifiers
 * @format: Format string
 * @args: Variable argument list
 * Return: Number of characters printed
 */
int handle_conversion(const char *format, va_list args)
{
    int count = 0;

    if (format == NULL)
        return (-1);

    switch (*format)
    {
        case 'd':
        case 'i':
            count += _print_d(args);
            break;
        case 'u':
            count += _print_u(args);
            break;
        case 'o':
            /*  Call _print_o function... */
            break;
        case 'x':
        case 'X':
            /*  Call _print_x function... */
            break;
        /*  Add cases for other conversion specifiers... */
        default:
            write(1, format - 1, 1);
            write(1, format, 1);
            count += 2;
            break;
    }

    return (count);
}

