#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    void *point;
    
    ft_printf(" %c ", 'a');
    printf(";");
    printf("\n");
    printf(" %c ", 'a');
    printf(";");
}