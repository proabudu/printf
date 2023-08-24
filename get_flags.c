#include "main.h"

int get_flags(const char *format, int *i)
{
    int flags = 0;
    const char FLAGS_CH[] = "-+0# ";
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE};

    for (int curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        char currentChar = format[curr_i];
        int j;
        for (j = 0; FLAGS_CH[j] != '\0'; j++)
        {
            if (currentChar == FLAGS_CH[j])
            {
                flags |= FLAGS_ARR[j];
                break;
            }
        }

        if (FLAGS_CH[j] == '\0')
            break;
    }

    *i = *i + flags; 
/* Update the index with the processed flags */

    return flags;
}
