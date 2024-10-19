#include "ft_printf.h"

int	ft_baselen(unsigned long long n, unsigned long long len)
{
	int	index;

	index = 0;
	while (n > len - 1)
	{
		n /= len;
		index++;
	}
	return (index + 1);
}

char    *ft_convert_base(unsigned long long nb, const char *base)
{
    unsigned long long   size;
    int         index;
    char                *result;

    size = ft_strlen(base);
    index = ft_baselen(nb, size);
    result = ft_calloc(index + 1, sizeof(char));
    while (index > 0)
    {
        result[index - 1] = base[nb % size];
        nb = nb / size;
        index--;
    }
    return (result);
}

char    *ft_command_p(void *point)
{
    char    *result;
    char    *hex;

    hex = ft_convert_base((unsigned long)point, L_HEX);
    result = ft_strjoin("0x", hex);
    free(hex);
    return (result);
}

char    *ft_command_d(long nb)
{
    char    *result;
    char    *minus;
    char    *dec;
    
    minus = NULL;
    if (nb < 0)
    {
        minus = ft_strdup("-");
        nb *= -1;
    }
    dec = ft_convert_base(nb, DEC);
    result = ft_strjoin(minus, dec);
    if (minus)
        free(minus);
    free(dec);
    return (result);
}

char    *ft_command_u(unsigned int nb, char *base)
{
    return (ft_convert_base(nb, base));
}