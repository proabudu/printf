#include "main.h"

int print_unsigned(va_list types, char buffer[],
                   int flags, int width, int precision, int size);

int print_octal(va_list types, char buffer[],
                int flags, int width, int precision, int size);

int print_hexadecimal(va_list types, char buffer[],
                      int flags, int width, int precision, int size);

int print_hexa_upper(va_list types, char buffer[],
                     int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[], char buffer[],
               int flags, char flag_ch, int width, int precision, int size);

void write_to_buffer(char buffer[], int *buff_ind, char c);

int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    va_list list;
    va_start(list, format);

    int printed_chars = 0;
    char buffer[BUFF_SIZE];
    int buff_ind = 0;

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            print_buffer(buffer, &buff_ind);

            i++; // Move past '%'
            int flags = get_flags(format, &i);
            int width = get_width(format, &i, list);
            int precision = get_precision(format, &i, list);
            int size = get_size(format, &i);

            int printed = handle_print(format, &i, list, buffer,
                                       flags, width, precision, size);
            if (printed == -1)
            {
                va_end(list);
                return -1;
            }

            printed_chars += printed;
        }
        else
        {
            write_to_buffer(buffer, &buff_ind, format[i]);
            printed_chars++;
        }
    }

    print_buffer(buffer, &buff_ind);

    va_end(list);

    return printed_chars;
}

void write_to_buffer(char buffer[], int *buff_ind, char c)
{
    buffer[*buff_ind] = c;
    (*buff_ind)++;
    if (*buff_ind == BUFF_SIZE)
    {
        print_buffer(buffer, buff_ind);
    }
}
