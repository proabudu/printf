#include <unistd.h>
#include "conversion_utils.h"

/**
 * print_octal - Print an unsigned integer in octal
 * @n: Unsigned integer to print
 * Return: Number of characters printed
 */
int print_octal(unsigned int n)
{
    char octal[12];
    int count = 0, i = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    while (n > 0)
    {
        octal[i] = (n % 8) + '0';
        n /= 8;
        i++;
    }

    while (i > 0)
    {
        write(1, &octal[i - 1], 1);
        count++;
        i--;
    }

    return count;
}

/**
 * print_hexadecimal - Print an unsigned integer in hexadecimal
 * @n: Unsigned integer to print
 * @uppercase: Whether to use uppercase letters for A-F (1) or not (0)
 * Return: Number of characters printed
 */
int print_hexadecimal(unsigned int n, int uppercase)
{
    char hex[16];
    int count = 0, i = 0;

    while (i < 10)
    {
        hex[i] = i + '0';
        i++;
    }

    while (i < 16)
    {
        hex[i] = (uppercase ? 'A' : 'a') + (i - 10);
        i++;
    }

    char hexadecimal[12];
    i = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    while (n > 0)
    {
        hexadecimal[i] = hex[n % 16];
        n /= 16;
        i++;
    }

    while (i > 0)
    {
        write(1, &hexadecimal[i - 1], 1);
        count++;
        i--;
    }

    return count;
}

