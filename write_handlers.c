#include "main.h"

int handle_write_char(char c, char buffer[],
    int flags, int width, int precision, int size)
{
    int printed_chars = 1;
    char padd = (flags & F_ZERO) ? '0' : ' ';

    if (width > 1)
    {
        if (flags & F_MINUS)
        {
            write(1, &c, 1);
            printed_chars += write_padding(buffer, width - 1, padd);
        }
        else
        {
            printed_chars += write_padding(buffer, width - 1, padd);
            write(1, &c, 1);
        }
    }
    else
    {
        write(1, &c, 1);
    }

    return printed_chars;
}

int write_number(int is_negative, int ind, char buffer[],
    int flags, int width, int precision, int size)
{
    int length = BUFF_SIZE - ind - 1;
    char padd = (flags & F_ZERO) ? '0' : ' ';
    char extra_ch = get_extra_char(is_negative, flags);

    return write_num(ind, buffer, width, length, padd, extra_ch);
}

int write_num(int ind, char buffer[], int width, int length, char padd, char extra_c)
{
    if (extra_c != 0)
        length++;

    if (width > length)
    {
        write_padding(buffer, width - length, padd);
        if (extra_c)
            buffer[--ind] = extra_c;
    }

    return write(1, &buffer[ind], length);
}

int write_unsgnd(int is_negative, int ind,
    char buffer[], int flags, int width, int precision, int size)
{
    int length = BUFF_SIZE - ind - 1;
    char padd = (flags & F_ZERO) ? '0' : ' ';

    if (precision > length)
    {
        write_padding(buffer, precision - length, '0');
    }

    return write_num(ind, buffer, width, length, padd, 0);
}

int write_pointer(char buffer[], int ind, int length,
    int width, int flags, char padd, char extra_c, int padd_start)
{
    if (width > length)
    {
        write_padding(buffer, width - length, padd);
        buffer[1] = '0';
        buffer[2] = 'x';
        if (extra_c)
            buffer[--padd_start] = extra_c;
    }

    return write(1, &buffer[ind], BUFF_SIZE - ind - 1);
}

int get_extra_char(int is_negative, int flags)
{
    if (is_negative)
        return '-';
    if (flags & F_PLUS)
        return '+';
    if (flags & F_SPACE)
        return ' ';
    return 0;
}

int write_padding(char buffer[], int count, char padd)
{
    int i;
    for (i = 0; i < count; i++)
    {
        buffer[i] = padd;
    }
    buffer[i] = '\0';
    return write(1, buffer, i);
}
