/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vim hello.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaraton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:05:03 by ebaraton          #+#    #+#             */
/*   Updated: 2022/04/21 15:15:26 by ebaraton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choix(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar((va_arg (args, int))));
	else if (c == 's')
		return (ft_putstr((va_arg (args, char *))));
	else if (c == 'd' || c == 'i')
		return (ft_printnb((va_arg (args, int))));
	else if (c == 'p')
		return (ft_pointeur((va_arg (args, unsigned long)), 87, 0));
	else if (c == 'u')
		return (ft_printnb((va_arg (args, unsigned int))));
	else if (c == 'x')
		return (ft_pointeur((va_arg (args, unsigned int)), 87, 1));
	else if (c == 'X')
		return (ft_pointeur((va_arg (args, unsigned int)), 55, 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	count = 0;
	i = -1;
	va_start (args, str);
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			count += ft_choix(str[i + 1], args);
			i++;
		}
		else if (str[i] == '%' && ft_strstr((char *)str, i + 1))
		{
			count++;
			i++;
		}
		else
			count += ft_putchar(str[i]);
	}
	va_end (args);
	return (count);
}
