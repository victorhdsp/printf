/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:18:20 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/19 07:24:45 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_command_c(char *flag, int c)
{
    char    *result;

    result = ft_calloc(2, sizeof(char));
    result[0] = c;
    result = ft_width(flag, result);
    return (result);
}

char    *ft_command_s(char *flag, char *str)
{
    char    *result;

    result = ft_strdup(str);
    if ((int)*flag == '.')
        while (ft_strchr(".0123456789", (int)*flag))
            flag++;
    result = ft_width(flag, result);
    return (result);
}