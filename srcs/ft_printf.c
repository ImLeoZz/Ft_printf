/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemille <lemille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 08:31:02 by lemille           #+#    #+#             */
/*   Updated: 2026/11/24 16:02:59 by lemille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

int	ft_printf(const char *f, ...)
{
	va_list	args;
	size_t	k;
	size_t	t;
	int		a;

	k = 0;
	t = 0;
	va_start(args, f);
	while (f[k])
	{
		if (f[k] == '%')
		{
			t++;
			a = va_arg(args, int);
		}
		else
			write(1, &f[k], 1);
		k++;
	}
	va_end(args);
	return (t);
}
