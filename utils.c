#include <unistd.h>
#include "main.h"

/* Declare the _str_reverse function */
void _str_reverse(char *str);

/* Rest of the utility functions... */

/**
 * _itoa - Convert an integer to a string
 * @num: Integer to convert
 * @str: Buffer to store the converted string
 * Return: Pointer to the converted string
 */
char *_itoa(int num, char *str)
{
    /* ... Rest of the _itoa function ... */

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

