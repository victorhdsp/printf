#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    void *point;
    int count;
    
    count = ft_printf(" % d ", -1);
    printf(", count: %d;\n", count);
    count = printf(" % d ", -1);
    printf(", count: %d;\n", count);
}