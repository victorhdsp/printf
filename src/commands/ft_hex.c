/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:28:56 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/25 10:20:14 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_precision(t_flag_data *flag_data)
{
	if (!flag_data->has_precision)
		return ;
	flag_data->width = flag_data->precision;
	flag_data->set = '0';
}

int	ft_command_hex_n(t_flag_data *flag_data, unsigned long nb, int upper)
{
	size_t	count;
	char	*result;
	char	*tmp;
	size_t	index;

	index = 0;
	count = 0;
	ft_precision(flag_data);
	tmp = ft_convert_base(nb, HEX);
	if (nb != 0)
		result = ft_strjoin(flag_data->prefix, tmp);
	else
		result = ft_strjoin(NULL, tmp);
	free(tmp);
	result = ft_fill(flag_data, result);
	while (upper && result && result[index])
	{
		result[index] = ft_toupper(result[index]);
		index++;
	}
	count += ft_putstr(result);
	free(result);
	free(flag_data);
	return (count);
}

int	ft_command_x_n(char *flag, unsigned int nb)
{
	t_flag_data	*flag_data;
	size_t		count;

	count = 0;
	flag_data = ft_create_flag_data();
	ft_get_flag_data(flag, flag_data);
	return (ft_command_hex_n(flag_data, nb, 0));
}

int	ft_command_upperx_n(char *flag, unsigned int nb)
{
	t_flag_data	*flag_data;
	size_t		count;

	count = 0;
	flag_data = ft_create_flag_data();
	ft_get_flag_data(flag, flag_data);
	return (ft_command_hex_n(flag_data, nb, 1));
}

int	ft_command_p_n(char *flag, void *point)
{
	t_flag_data	*flag_data;
	size_t		count;

	count = 0;
	if (!point)
		return (ft_command_s_n(flag, "(nil)"));
	flag_data = ft_create_flag_data();
	ft_get_flag_data(flag, flag_data);
	flag_data->prefix = "0x";
	return (ft_command_hex_n(flag_data, (unsigned long)point, 0));
}
