/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:47:21 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/17 20:54:30 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(unsigned char c)
{
    write(1, &c, 1);
}

void ft_putstr(unsigned char *str)
{
    int index;

    index = 0;
    while (str[index])
    {
        ft_putchar(str[index]);
        index++;
    }
}

int ft_strlen(const char *str)
{
    int index;

    index = 0;
    while (str[index])
        index++;
    return(index);
}

void ft_convert_base(long long nb, const char *base)
{
    long long size;
    
    size = ft_strlen(base);
	if (nb < 0)
    {
        ft_putchar('-');
        nb *= -1;
    }
    if (nb > size - 1)
		ft_convert_base(nb / size, base);
	ft_putchar(base[nb % size]);
}