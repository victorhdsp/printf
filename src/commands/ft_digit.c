/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:28:56 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/23 18:18:58 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void ft_precision(t_flag_data *flag_data)
{
    if (!flag_data->has_precision)
        return;
    flag_data->width = flag_data->precision;
    flag_data->set = '0';
    if (flag_data->prefix && flag_data->prefix[0] == '-')
        flag_data->width++;
}

static long ft_minus_traitment(t_flag_data *flag_data, long nb)
{
    if (nb >= 0)
        return (nb);
    flag_data->prefix = "-";
    return (nb * -1);
}

int ft_command_d_n(char *flag, long nb)
{
	t_flag_data *flag_data;
    size_t      count;
    char        *result;
    char        *tmp;
    
    count = 0;
    flag_data = ft_create_flag_data();
    ft_get_flag_data(flag, flag_data);
	nb = ft_minus_traitment(flag_data, nb);
    tmp = ft_convert_base(nb, DEC);
    result = ft_strjoin(flag_data->prefix, tmp);
    ft_precision(flag_data);
    if (flag_data->set == '0' && flag_data->prefix)
        result[0] = '0';
    result = ft_fill(flag_data, result);
    if (flag_data->set == '0' && flag_data->prefix)
        result[0] = flag_data->prefix[0];
    count += ft_putstr(result);
    free(tmp);
    free(result);
    free(flag_data);
    return (count);
}
