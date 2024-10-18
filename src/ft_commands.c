#include "ft_printf.h"

int ft_command_p(unsigned int point)
{
    ft_putstr((unsigned char *)"0x");
    ft_convert_base(point, U_HEX);
    return (1);
}

int ft_command_c(char c)
{
    ft_putchar((unsigned char)c);
    return (1);
}

int ft_command_s(char *str)
{
    ft_putstr((unsigned char *)str);
    return (ft_strlen(str));
}

int ft_command_d(int nb)
{
    ft_convert_base(nb, DEC);
    return (1);
}

int ft_command_u(unsigned int nb)
{
    ft_convert_base(nb, DEC);
    return (1);
}

int ft_command_x(unsigned int nb)
{
    ft_convert_base(nb, L_HEX);
    return (1);
}


int ft_command_X(unsigned int nb)
{
    ft_convert_base(nb, U_HEX);
    return (1);
}