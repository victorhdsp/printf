/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:28:56 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/23 18:08:02 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_command_c_n(char *flag, int c)
{
	t_flag_data	*flag_data;
	size_t		count;
	char		*result;

	count = 0;
	result = NULL;
	flag_data = ft_create_flag_data();
	ft_get_flag_data(flag, flag_data);
	if (!c && flag_data->align)
		count += ft_putchar(0);
	if (c)
	{
		result = ft_calloc(2, sizeof(char *));
		result[0] = c;
	}
	result = ft_fill(flag_data, result);
	if (result)
	{
		count += ft_putstr(result);
		free(result);
	}
	if (!c && !flag_data->align)
		count += ft_putchar(0);
	free(flag_data);
	return (count);
}
