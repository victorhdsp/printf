/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:54:54 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/17 22:23:06 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_interpreter(char c, va_list args)
{
    if (c == 's')
        ft_command_s(va_arg(args, char *));
    if (c == 'c')
        ft_command_c(va_arg(args, int));
    if (c == 'p')
        ft_command_p((unsigned int)va_arg(args, unsigned int));
    if (c == 'd' || c == 'i')
        ft_command_d(va_arg(args, int));
    if (c == 'u')
        ft_command_u(va_arg(args, unsigned int));
    if (c == 'x')
        ft_command_x(va_arg(args, unsigned int));
    if (c == 'X')
        ft_command_X(va_arg(args, unsigned int));
    if (c == '%')
        ft_command_c('%');
    else
        return (0);
    return (2);
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

    va_start(args, str);
    ft_reader(str, args);
    va_end(args);
    return (1);
}