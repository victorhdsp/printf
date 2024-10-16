#include "printf.h"
#include <stdio.h>

int ft_interpreter(char c, int fd)
{
    //printf("%c", c);
    if (c == '%')
        ft_putchar_fd('%', fd);
    else
        return (0);
    return (2);
}

int ft_reader(const char *str, int fd, ...)
{
    size_t  index;

    index = 1;
    while (str && *str)
    {
        if (*str != '%')
        {
            ft_putchar_fd(*str, fd);
            index = 1;
        }
        else
            index = ft_interpreter(*(str + 1), fd);
        if (!index)
            return (0);
        str += index;
    }
    return (1);
}