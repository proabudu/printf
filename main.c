#include "main.h"

int main(void)
{
    int len;

    len = _printf("Hello, %s!\n", "world");
    _printf("Characters printed: %d\n", len);

    len = _printf("Binary of %u is %b\n", 42, 42);
    _printf("Characters printed: %d\n", len);

    // Add more test cases to thoroughly test your _printf function

    return (0);
}

