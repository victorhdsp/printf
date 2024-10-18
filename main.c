#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    void *point;
    int count;
    
    count = ft_printf("este é um char: %p, %p", 0, 0);
    printf(", count: %d;\n", count);
    count = printf("este é um char: %p, %p", (void *)0, (void *)0);
    printf(", count: %d;\n", count);
}