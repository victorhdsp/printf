/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:54:54 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/23 10:44:46 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *ft_select_command(char c, char *str, va_list args)
{
    if (c == 'c')
        return (ft_command_c(str, va_arg(args, int)));
    else if (c == 's')
        return (ft_command_s(str, va_arg(args, char *)));
    else if (c == 'p')
        return (ft_command_p(str, va_arg(args, void *)));
    else if (c == 'd' || c == 'i')
        return (ft_command_d(str, va_arg(args, int)));
    else if (c == 'u')
        return (ft_command_u(str, va_arg(args, unsigned int), DEC));
    else if (c == 'x')
        return (ft_command_u(str, va_arg(args, unsigned int), L_HEX));
    else if (c == 'X')
        return (ft_command_u(str, va_arg(args, unsigned int), U_HEX));
    else if (c == '%')
        return (ft_command_c(str, (int)'%'));
    return (NULL);
}

static int ft_interpreter(const char *c, va_list args, size_t *count)
{  
    char    *flags;
    char    *result;
    size_t  len;

    flags = (char *)c;
    while (ft_strchr("# -+.0123456789", (int)*flags))
        flags++;
    *count = ft_strlen(c) - ft_strlen(flags);
    if (!ft_strchr("cspdiuxX%", (int)*flags))
        return (0);
    *count += 1;
    result = ft_select_command(*flags, (char *)c, args);
    if (!result)
        return (ft_traitment_null(*flags, (char *)c));
    len = ft_putstr(result);
    free(result);
    return (len);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    size_t  index;
    size_t  count;
    size_t  len;

    index = 0;
    len = 0;
    count = 0;
    va_start(args, str);
    while (str && str[index])
    {
        if (str[index] == '%')
        {
            len += ft_interpreter(&str[index + 1], args, &count);
            index += count;
        }
        else
        {
            ft_putchar(str[index]);
            len++;
        }
        index++;
    }
    va_end(args);
    return ((int)len);
}