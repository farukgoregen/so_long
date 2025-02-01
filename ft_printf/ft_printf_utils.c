/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:11:55 by omgorege          #+#    #+#             */
/*   Updated: 2024/10/27 13:44:23 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long i, int base, char *pase)
{
	size_t	s;

	s = 0;
	if (i < 0)
	{
		s += ft_putchar('-');
		i *= -1;
	}
	if (i < base)
	{
		s += ft_putchar(pase[i]);
	}
	else
	{
		s += ft_putnbr(i / base, base, pase);
		s += ft_putnbr(i % base, base, pase);
	}
	return (s);
}

int	ft_ptrnbr(size_t i, size_t base, char *pase)
{
	size_t	s;

	ft_putchar('0');
	ft_putchar('x');
	s = 2;
	if (i < base)
	{
		s += ft_putchar(pase[i]);
	}
	else
	{
		s += ft_putnbr(i / base, base, pase);
		s += ft_putnbr(i % base, base, pase);
	}
	return (s);
}
