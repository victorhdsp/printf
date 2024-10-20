/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitment_null.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:54:54 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/19 08:28:34 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void    ft_putwidth(int size)
{
    while (size > 0)
    {
        ft_putchar(' ');
        size--;
    }
}

static int ft_traitment_null_c(char *str)
{
    int     has_end;
    int     width;

    while (ft_strchr("# -+", (int)*str))
    {
        if ((int)*str == '-')
            has_end = 1;
        str++;
    }
    while (ft_strchr("0123456789", (int)*str))
    {
        width = width * 10 + ((int)*str - '0');
        str++;
    }
    if (has_end)
    {
        ft_putwidth(width - 1);
        ft_putchar(0);
    }
    else
    {
        ft_putchar(0);
        ft_putwidth(width - 1);
    }
    if (width < 0)
        width = 1;
    return (width);
}

int ft_traitment_null(char c, char *str, va_list args)
{
    char    *result;
    int     len;
    va_list clean_args;

    len = 0;
    va_copy(clean_args, args);
    if (c == 'c')
        if (!va_arg(clean_args, int))
            len = ft_traitment_null_c(str);
    if (c == 's')
        if (!va_arg(clean_args, char *))
        {
            result = ft_command_s(str, "(null)");
            len = ft_putstr(result);
            free(result);
        }
    if (c == 'p')
        if (!va_arg(clean_args, void *))
        {
            result = ft_command_s(str, "(nil)");
            len = ft_putstr(result);
            free(result);
        }
    if (len)
        (void) va_arg(args, void *);
    return (len);
}