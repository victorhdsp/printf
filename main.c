#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    void *point;
    int count;
    
    count = ft_printf("%c ", '0' + 256);
    printf(", count: %d;\n", count);
    count = printf("%c ", '0' + 256);
    printf(", count: %d;\n", count);
}