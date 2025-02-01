/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:11:59 by omgorege          #+#    #+#             */
/*   Updated: 2024/10/27 13:05:10 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(int c);
int		ft_printf(const char *format, ...);
int		ft_putstr(char *str);
int		ft_putnbr(long i, int base, char *pase);
int		ft_ptrnbr(size_t i, size_t base, char *pase);
#endif
