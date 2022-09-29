/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaraton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:26:14 by ebaraton          #+#    #+#             */
/*   Updated: 2022/04/21 15:26:19 by ebaraton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_countnb(long long int nb);
void	ft_putnb(long int nb);
int		ft_printnb(long nb);
void	ft_convert(unsigned long adresse, int ascii, int *count);
int		ft_pointeur(unsigned long adresse, int ascii, int choix);
int		ft_strstr(char *str, int i);
int		ft_choix(char c, va_list args);
int		ft_printf(const char *str, ...);

#endif
