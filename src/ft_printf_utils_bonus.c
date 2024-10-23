/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:47:21 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/23 14:18:45 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_prefix(char *flag, char *str)
{
	char	*result;
	char	prefix[2];

	if (!ft_strchr(" +", *flag))
		return (str);
	prefix[0] = *flag;
	prefix[1] = '\0';
	result = ft_strjoin(prefix, str);
	free(str);
	return (result);
}

char	*ft_width(char *flag, char *str)
{
	char	*result;
	int		start;
	size_t	width;
	int		in_right;
	char	set;

	start = 0;
	width = 0;
	in_right = 0;
	set	= ' ';
	while (ft_strchr("# -+0", *flag))
	{
		if (*flag == '-')
			in_right = 1;
		if (*flag == '0')
			set = '0';
		flag++;
	}
	while (ft_strchr("0123456789", *flag))
	{
		width = (width * 10) + (*flag - '0');
		flag++;
	}
	if (ft_strlen(str) >= width)
		return (str);
	result = ft_calloc(width + 1, sizeof(char));
	ft_memset(result, set, width);
	if (!in_right)
		start = width - ft_strlen(str);
	ft_memcpy(result + start, str, ft_strlen(str));
	free(str);
	return (result);
}

char	*ft_precision_string(char *flag, char *str)
{
	char	*result;
	size_t	size;

	size = 0;
	if (ft_strchr(flag, '.'))
	{
		while (ft_strchr("# -+0123456789", *flag))
			flag++;
		if (*flag == '.')
			flag++;
		while (ft_strchr("0123456789", *flag))
		{
			size = (size * 10) + (*flag - '0');
			flag++;
		}
	}
	else
		return (str);
	if (ft_strlen(str) <= size)
		return (str);
	result = ft_calloc(size + 1, sizeof(char));
	ft_memcpy(result, str, size);
	free(str);
	return (result);
}

char	*ft_precision_digit(char *flag, char *str)
{
	char	*result;
	size_t	size;
	int		start;
	char	minus;

	size = 0;
	minus = 0;
	if (ft_strchr(flag, '.'))
	{
		while (ft_strchr("# -+0123456789", *flag))
			flag++;
		if (*flag == '.')
			flag++;
		while (ft_strchr("0123456789", *flag))
		{
			size = (size * 10) + (*flag - '0');
			flag++;
		}
	}
	else
		return (str);
	if (*str == '-')
	{
		minus = '-';
		str[0] = '0';
		size++;
	}
	if (ft_strlen(str) >= size)
		return (str);
	result = ft_calloc(size + 1, sizeof(char));
	ft_memset(result, '0', size);
	start = size - ft_strlen(str);
	ft_memcpy(result + start, str, ft_strlen(str));
	free(str);
	if (minus)
		result[0] = '-';
	return (result);
}