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

char	*ft_convert_base(unsigned long long nb, const char *base)
{
	unsigned long long	size;
	int					index;
	char				*result;

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

char	*ft_command_p(char *flag, unsigned long point)
{
	char	*result;
	char	*hex;

	if (!point)
		return (NULL);
	hex = ft_convert_base(point, HEX);
	result = ft_strjoin("0x", hex);
	free(hex);
	if ((int)*flag == '.')
		while (ft_strchr(".0123456789", (int)*flag))
			flag++;
	result = ft_width(flag, result);
	return (result);
}

char	*ft_command_d(char *flag, long nb)
{
	char	*result;
	char	*minus;
	char	*dec;

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
	else
		result = ft_prefix(flag, result);
	free(dec);
	result = ft_precision_digit(flag, result);
	if (result[0] == '-' && flag[0] == '0')
	{
		result[0] = '0';
		minus = "-";
	}
	result = ft_width(flag, result);
	if (minus)
		result[0] = '-';
	return (result);
}

char	*ft_command_x(char *flag, unsigned int nb, int upper)
{
	char	*result;
	int		has_prev;
	size_t	index;

	has_prev = 0;
	index = 0;
	(void) upper;
	if (*flag == '#')
		result = ft_command_p(flag, nb);
	else
		result = ft_convert_base(nb, HEX);
	result = ft_precision_digit(flag, result);
	result = ft_width(flag, result);
	if (upper)
		while (result && result[index])
		{
			result[index] = ft_toupper(result[index]);
			index++;
		}
	return (result);
}