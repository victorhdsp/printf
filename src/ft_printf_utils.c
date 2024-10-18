/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:47:21 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/18 18:32:35 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(unsigned char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(unsigned char *str)
{
    int index;

    index = 0;
    while (str[index])
    {
        ft_putchar(str[index]);
        index++;
    }
    return (index);
}

int ft_strlen(const char *str)
{
    int index;

    index = 0;
    while (str[index])
        index++;
    return(index);
}

int ft_convert_base(unsigned long long nb, const char *base)
{
    unsigned long long   size;
    int         index;
    
    index = 0;
    size = ft_strlen(base);
    if (nb > size - 1)
		index += ft_convert_base(nb / size, base);
	return index + ft_putchar(base[nb % size]);
}