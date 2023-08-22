#include "main.h"

/**
 * get_size - Get and process length modifiers
 * @format: Format string
 * Return: Length modifier
 */
int get_size(const char *format)
{
    int length_modifier = LENGTH_NONE; /*  Default value for no length modifier */

    if (format == NULL)
        return (LENGTH_NONE);

    while (*format)
    {
        switch (*format)
        {
            case 'h':
                if (*(format + 1) == 'h') /*  Check for 'hh' length modifier */
                {
                    length_modifier = LENGTH_HH;
                    format += 2; /*  Move past 'hh' */ 
                }
                else
                {
                    length_modifier = LENGTH_H;
                    format++; /*  Move past 'h' */
                }
                break;
            case 'l':
                if (*(format + 1) == 'l') /*  Check for 'll' length modifier */
                {
                    length_modifier = LENGTH_LL;
                    format += 2; /*  Move past 'll' */
                }
                else
                {
                    length_modifier = LENGTH_L;
                    format++; 
                }
                break;
            default:

                format++;
                break;
        }
    }

    return length_modifier;
}

