/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:47:21 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/23 16:49:38 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		ft_putchar(str[index]);
		index++;
	}
	return (index);
}

static int	ft_baselen(unsigned long long n, unsigned long long len)
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
