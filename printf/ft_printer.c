/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vim ft_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaraton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:56:58 by ebaraton          #+#    #+#             */
/*   Updated: 2022/04/21 15:25:24 by ebaraton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countnb(long long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_printnb(long nb)
{
	int	i;

	ft_putnb(nb);
	i = ft_countnb(nb);
	return (i);
}

void	ft_convert(unsigned long adresse, int ascii, int *count)
{
	if (adresse > 15)
	{
		ft_convert(adresse / 16, ascii, count);
		ft_convert(adresse % 16, ascii, count);
	}
	else if (adresse + 48 >= 58 && adresse + 48 <= 63)
		*count += ft_putchar(adresse + ascii);
	else
		*count += ft_putchar(adresse + 48);
	return ;
}

int	ft_strstr(char *str, int i)
{
	while (str[i])
	{	
		if (str[i] == '%')
		{
			write(1, "%", 1);
			return (1);
		}
		i++;
	}
	return (0);
}
