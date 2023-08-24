#include "main.h"

int get_width(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int width = 0;

    for (; format[curr_i] != '\0'; curr_i++)
    {
        char currentChar = format[curr_i];

        if (is_digit(currentChar))
        {
            width = (width * 10) + (currentChar - '0');
        }
        else if (currentChar == '*')
        {
            curr_i++;
            width = va_arg(list, int);
            break;
        }
        else
        {
            break;
        }
    }

    *i = curr_i - 1;

    return width;
}

