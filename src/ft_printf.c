/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:54:54 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/18 18:37:17 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_interpreter(char c, va_list args)
{
    if (c == 's')
        return (ft_command_s(va_arg(args, char *)));
    if (c == 'c')
        return (ft_command_c(va_arg(args, int)));
    if (c == 'p')
        return (ft_command_p(va_arg(args, void *)));
    if (c == 'd' || c == 'i')
        return (ft_command_d(va_arg(args, int)));
    if (c == 'u')
        return (ft_command_u(va_arg(args, unsigned int)));
    if (c == 'x')
        return (ft_command_x(va_arg(args, unsigned int)));
    if (c == 'X')
        return (ft_command_X(va_arg(args, unsigned int)));
    if (c == '%')
        return (ft_command_c('%'));
    return (0);
}

static int ft_reader(const char *str, va_list args)
{
    size_t  index;
    size_t  len;

    index = 0;
    len = 0;
    while (str && str[index])
    {
        if (str[index] == '%')
        {
            len += ft_interpreter(str[index + 1], args);
            index++;
        }
        else
            len += ft_command_c(str[index]);
        index++;
    }
    return (len);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int len;

    va_start(args, str);
    len = ft_reader(str, args);
    va_end(args);
    return (len);
}