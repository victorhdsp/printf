/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:47:21 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/23 21:35:56 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag_data	*ft_create_flag_data(void)
{
	t_flag_data	*flag_data;
	int			size;

	size = sizeof(t_flag_data *) + sizeof(size_t) + sizeof(size_t) + sizeof(int)
		+ sizeof(char) + sizeof(char *) + sizeof(int);
	flag_data = ft_calloc(1, size);
	flag_data->width = 0;
	flag_data->has_precision = 0;
	flag_data->precision = 0;
	flag_data->align = 0;
	flag_data->set = ' ';
	flag_data->prefix = NULL;
	return (flag_data);
}
static void	ft_firstflag(char *flag, t_flag_data *flag_data)
{
	if (*flag == '-')
		flag_data->align = 1;
	if (*flag == '0')
		flag_data->set = '0';
	if (*flag == '#')
		flag_data->prefix = "0x";
	if (*flag == '+')
		flag_data->prefix = "+";
	if (*flag == ' ')
		flag_data->prefix = " ";
}
void	ft_get_flag_data(char *flag, t_flag_data *flag_data)
{
	while (ft_strchr("# -+0", *flag) && *flag)
	{
		ft_firstflag(flag, flag_data);
		flag++;
	}
	while (ft_strchr(DEC, *flag) && *flag)
	{
		flag_data->width = (flag_data->width * 10) + (*flag - '0');
		flag++;
	}
	while (ft_strchr(".", *flag) && *flag)
	{
		flag_data->has_precision = 1;
		flag++;
	}
	while (ft_strchr(DEC, *flag) && *flag)
	{
		flag_data->precision = (flag_data->precision * 10) + (*flag - '0');
		flag++;
	}
}

char	*ft_fill(t_flag_data *flag_data, char *str)
{
	char	*result;
	size_t	start;

	start = 0;
	if ((!str) && flag_data->width > 0)
		flag_data->width -= 1;
	if (flag_data->width <= 0 || flag_data->width <= ft_strlen(str))
		return (str);
	result = ft_calloc(flag_data->width + 1, sizeof(char *));
	ft_memset(result, flag_data->set, flag_data->width);
	if (!flag_data->align)
		start = flag_data->width - ft_strlen(str);
	ft_memcpy(result + start, str, ft_strlen(str));
	if (str)
		free(str);
	return (result);
}
char	*ft_substr(t_flag_data *flag_data, char *str)
{
	char	*result;
	
	if (!flag_data->has_precision)
		return (str);
	if (ft_strlen(str) <= flag_data->precision)
		return (str);
	result = ft_calloc(flag_data->precision + 1, sizeof(char));
	ft_memcpy(result, str, flag_data->precision);
	free(str);
	return (result);
}
