#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    void *point;
    int count;
    
    count = ft_printf(" %-1c %-2c %-3c ", '0', 0, '1');
    printf(", count: %d;\n", count);
    count = printf(" %-1c %-2c %-3c ", '0', 0, '1');
    printf(", count: %d;\n", count);
}