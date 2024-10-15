#include "printf.h"

int ft_reader(const char *str, int fd, ...)
{
    size_t  index;
    size_t  len;

    index = 0;
    len = ft_strlen(str);
    while (index < len)
    {
        write (fd, &str[index], 1);
        index++;
    }
    return (1);
}