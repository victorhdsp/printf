# ifndef PRINTF_H
#define PRINTF_H

#include <unistd.h>
#include "libft.h"

int ft_printf(const char *str, ...);
int ft_reader(const char *str, int fd, ...);

#endif