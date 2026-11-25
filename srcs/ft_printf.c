/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemille <lemille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 08:31:02 by lemille           #+#    #+#             */
/*   Updated: 2026/11/25 14:22:59 by lemille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_print_hex(char symbol, va_list args)
{
	int				len;
	unsigned int	x;

	len = 0;
	if (symbol == 'x')
	{
		x = va_arg(args, unsigned int);
		len += ft_print_lowerhex(x);
	}
	else if (symbol == 'X')
	{
		x = va_arg(args, unsigned int);
		len += ft_print_upperhex(x);
	}
	return (len);
}

static int	ft_print_nbr(char symbol, va_list args)
{
	unsigned long int	u;
	int					len;
	int					di;

	len = 0;
	if (symbol == 'd' || symbol == 'i')
	{
		di = va_arg(args, int);
		len += ft_print_int(di);
	}
	if (symbol == 'u')
	{
		u = va_arg(args, unsigned int);
		len += ft_print_uint(u);
	}
	return (len);
}

static int	ft_print_str(char symbol, va_list args)
{
	int		len;
	char	*s;
	char	c;

	len = 0;
	if (symbol == 'c')
	{
		c = va_arg(args, int);
		len += ft_print_c(c);
	}
	if (symbol == 's')
	{
		s = va_arg(args, char *);
		len += ft_print_s(s);
	}
	return (len);
}

static int	ft_dispatch(char symbol, va_list args)
{
	int	len;

	if (symbol == 'c' || symbol == 's')
		len = ft_print_str(symbol, args);
	if (symbol == 'd' || symbol == 'i' || symbol == 'u')
		len = ft_print_nbr(symbol, args);
	if (symbol == 'x' || symbol == 'X')
		len = ft_print_hex(symbol, args);
	if (symbol == 'p')
		len = ft_print_p(&args);
	if (symbol == '%')
		len = ft_print_c('%');
	return (len);
}

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		blud;
	size_t	k;

	k = 0;
	blud = 0;
	va_start(args, f);
	while (f[k])
	{
		if (f[k] == '%')
			blud += ft_dispatch(f[++k], args);
		else
			blud += ft_print_c(f[k]);
		k++;
	}
	va_end(args);
	return (blud);
}
