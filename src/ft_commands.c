#include "ft_printf.h"

int ft_command_p(void *point)
{
    int len;

    if (!point)
        return (ft_command_s("(nil)"));
    len = 0;
    len += ft_putstr((unsigned char *)"0x");
    len += ft_convert_base((unsigned long)point, L_HEX);
    return (len);
}

int ft_command_c(char c)
{
    return (ft_putchar((unsigned char)c));
}

int ft_command_s(char *str)
{
    if (!str)
        return ft_command_s("(null)");
    return (ft_putstr((unsigned char *)str));
}

int ft_command_d(long nb)
{
    int         index;
    
    index = 0;
    if (nb < 0)
    {
        index += ft_putchar('-');
        nb *= -1;
    }
    return (index + ft_convert_base(nb, DEC));
}

int ft_command_u(unsigned int nb)
{
    return (ft_convert_base(nb, DEC));
}

int ft_command_x(unsigned int nb)
{
    return (ft_convert_base(nb, L_HEX));
}


int ft_command_X(unsigned int nb)
{
    return (ft_convert_base(nb, U_HEX));
}