/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemille <lemille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 08:31:02 by lemille           #+#    #+#             */
/*   Updated: 2026/11/25 08:10:07 by lemille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

static int	ft_dispatch(char symbol, va_list args)
{
	size_t	len;

	if (symbol == 'c' || symbol == 's')
		len = ft_print_str(args);
	if (symbol == 'd' || symbol == 'i' || symbol == 'u')
		len = ft_print_nbr(args);
	if (symbol == 'x' || symbol == 'X')
		len = ft_print_hex(args);
	return (len);
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
			blud += ft_dispatch(f[++k], args);
		else
			blud += ft_print_c(f[k]);
		k++;
	}
	va_end(args);
	return (blud);
}
