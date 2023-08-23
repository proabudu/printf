#include "string_utils.h"

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

