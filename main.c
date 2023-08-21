#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

int _printf(const char *format, ...);
int main()
{
_printf("Hello, %s!\n", "world");
return (0);
}
int _printf(const char *format, ...) 
{
/* Your _printf implementation here */  
}

