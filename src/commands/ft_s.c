/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:28:56 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/23 18:07:52 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_command_s_n(char *flag, char *str)
{
	t_flag_data	*flag_data;
	size_t		count;
	char		*result;

	count = 0;
	if (!str)
		return (ft_command_s_n(flag, "(null)"));
	flag_data = ft_create_flag_data();
	ft_get_flag_data(flag, flag_data);
	result = ft_strdup(str);
	result = ft_substr(flag_data, result);
	result = ft_fill(flag_data, result);
	count += ft_putstr(result);
	free(result);
	free(flag_data);
	return (count);
}
