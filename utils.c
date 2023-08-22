#include "main.h"

/**
 * _strlen - Calculate the length of a string
 * @str: Input string
 * Return: Length of the string
 */
int _strlen(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

/**
 * _putchar - Write a character to the standard output
 * @c: Character to write
 * Return: On success, return the character written. On error, return -1.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _puts - Write a string to the standard output
 * @str: String to write
 * Return: Number of characters written
 */
int _puts(const char *str)
{
    return write(1, str, _strlen(str));
}

/**
 * _itoa - Convert an integer to a string
 * @num: Integer to convert
 * @str: Buffer to store the converted string
 * Return: Pointer to the converted string
 */
char *_itoa(int num, char *str)
{
    int i = 0, is_negative = 0;

    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (num < 0)
    {
        is_negative = 1;
        num = -num;
    }

    while (num != 0)
    {
        int rem = num % 10;
        str[i++] = rem + '0';
        num = num / 10;
    }

    if (is_negative)
        str[i++] = '-';

    str[i] = '\0';

    _str_reverse(str);

    return str;
}

/**
 * _str_reverse - Reverse a string in-place
 * @str: String to reverse
 */
void _str_reverse(char *str)
{
    int left = 0;
    int right = _strlen(str) - 1;

    while (left < right)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

