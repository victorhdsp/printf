/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:47:21 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/23 10:34:04 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_width(char *flag, char *str)
{
    char    *result;
    int     start;
    size_t  width;
    int     in_right;

    start = 0;
    width = 0;
    in_right = 0;
    while (ft_strchr("# -+", *flag))
    {
        if (*flag == '-')
            in_right = 1;
        flag++;
    }
    while (ft_strchr("0123456789", *flag))
    {
        width = (width * 10) + (*flag - '0');
        flag++;
    }
    if (width <= ft_strlen(str))
        return (str);
    result = ft_calloc(width + 1, sizeof(char));
    ft_memset(result, ' ', width);
    if (!in_right)
        start = width - ft_strlen(str);
    ft_memcpy(result + start, str, ft_strlen(str));
    free(str);
    return (result);
}