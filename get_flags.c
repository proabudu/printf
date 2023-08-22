#include "main.h"

/**
 * get_flags - Get and process flag characters
 * @format: Format string
 * Return: Flags
 */
int get_flags(const char *format)
{
    int flags = 0;

    while (*format)
    {
        switch (*format)
        {
            case '+':
                flags |= FLAG_PLUS;
                break;
            case ' ':
                flags |= FLAG_SPACE;
                break;
            case '#':
                flags |= FLAG_HASH;
                break;
            default:
                /* Ignore other characters */
                break;
        }
        
        format++; /* Move to the next character in the format string */
    }

    return flags;
}

