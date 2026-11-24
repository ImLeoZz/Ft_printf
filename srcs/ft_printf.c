/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemille <lemille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 08:31:02 by lemille           #+#    #+#             */
/*   Updated: 2026/11/24 16:27:52 by lemille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

static int	ft_print_params(char symbol, va_list args)
{
	char	*s;
	size_t	k;
	char	c;

	k = 0;
	if (symbol == 'c')
	{
		c = va_arg(args, int);
		ft_putchar_fd(c, 1);
		k++;
	}
	else if (symbol == 's')
	{
		s = va_arg(args, char *);
		ft_putstr_fd(s, 1);
		k = ft_strlen(s);
	}
	return (k);
}

int	ft_printf(const char *f, ...)
{
	va_list	args;
	size_t	blud;
	size_t	k;

	k = 0;
	blud = 0;
	va_start(args, f);
	while (f[k])
	{
		if (f[k] == '%')
		{
			blud += ft_print_params(f[++k], args);
		}
		else
			write(1, &f[k], 1);
		k++;
	}
	va_end(args);
	return (blud + k);
}
