#include <stdio.h>
#include "main.h"

/**
 * print_hexadecimal - Print an unsigned integer in hexadecimal
 * @n: Unsigned integer to print
 * @uppercase: Whether to use uppercase letters (1) or not (0)
 * Return: Number of characters printed
 */
int print_hexadecimal(unsigned int n, int uppercase)
{
    char hexadecimal[12];
    int count = 0, i = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    while (n > 0)
    {
        int rem = n % 16;
        hexadecimal[i] = (rem < 10) ? (rem + '0') : (rem - 10 + ((uppercase) ? 'A' : 'a'));
        n /= 16;
        i++;
    }

    while (i > 0)
    {
        write(1, &hexadecimal[i - 1], 1);
        count++;
        i--;
    }

    return (count);
}

