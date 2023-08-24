#include "main.h"

int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    if (format[curr_i] != '.')
        return precision;

    precision = 0;

    for (curr_i++; format[curr_i] != '\0'; curr_i++)
    {
        char currentChar = format[curr_i];

        if (is_digit(currentChar))
        {
            precision = (precision * 10) + (currentChar - '0');
        }
        else if (currentChar == '*')
        {
            curr_i++;
            precision = va_arg(list, int);
            break;
        }
        else
        {
            break;
        }
    }

    *i = curr_i - 1;

    return precision;
}

