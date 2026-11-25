/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemille <lemille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 14:06:28 by lemille           #+#    #+#             */
/*   Updated: 2026/11/25 14:18:11 by lemille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_phex(unsigned long n)
{
	char	buff[20];
	char	*hex;
	int		len;
	int		i;

	i = 0;
	len = 0;
	hex = "0123456789abcdef";
	while (n > 0)
	{
		buff[i++] = hex[n % 16];
		n /= 16;
	}
	while (i > 0)
		len += ft_print_c(buff[--i]);
	return (len);
}

int	ft_print_p(void *p)
{
	int	len;

	len = 0;
	if (!p)
		len += ft_print_s("(nil)");
	else
	{
		len += ft_print_s("0x");
		len += ft_put_phex((unsigned long)p);
	}
	return (len);
}
