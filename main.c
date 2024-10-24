#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    void *point;
    int count;
    
    count = ft_printf(" %.13x ", 0);
    printf(", count: %d;\n", count);
    count = printf(" %.13x ", 0);
    printf(", count: %d;\n", count);
}