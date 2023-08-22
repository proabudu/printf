#include <unistd.h>
#include "main.h"

/**
 * write_string - Write a string to the standard output
 * @str: String to write
 * @len: Length of the string
 * Return: Number of characters written
 */
int write_string(const char *str, int len)
{
    return write(1, str, len);
}

/**
 * write_char - Write a character to the standard output
 * @c: Character to write
 * Return: Number of characters written (1)
 */
int write_char(char c)
{
    return write(1, &c, 1);
}

/**
 * write_integer - Write an integer to the standard output
 * @num: Integer to write
 * Return: Number of characters written
 */
int write_integer(int num)
{
    char buffer[12]; /*  Enough space for INT_MIN and null terminator */
    char *str = _itoa(num, buffer);
    return write_string(str, _strlen(str));
}

/**
 * write_unsigned - Write an unsigned integer to the standard output
 * @num: Unsigned integer to write
 * Return: Number of characters written
 */
int write_unsigned(unsigned int num)
{
    char buffer[12]; /*  Enough space for UINT_MAX and null terminator */
    char *str = _utoa(num, buffer);
    return write_string(str, _strlen(str));
}

/**
 * write_base - Write a number in a given base to the standard output
 * @num: Number to write
 * @base: Base of the number
 * @uppercase: Whether to use uppercase for hex (1) or not (0)
 * Return: Number of characters written
 */
int write_base(unsigned int num, int base, int uppercase)
{
    char buffer[40]; /*  More than enough space for base conversion */
    char *str = _utoa_base(num, buffer, base, uppercase);
    return write_string(str, _strlen(str));
}

/**
 * write_pointer - Write a pointer address to the standard output
 * @ptr: Pointer to write
 * Return: Number of characters written
 */
int write_pointer(void *ptr)
{
    return write_base((unsigned long)ptr, 16, 0);
}

