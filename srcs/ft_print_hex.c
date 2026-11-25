/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemille <lemille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 07:57:36 by lemille           #+#    #+#             */
/*   Updated: 2026/11/25 14:07:30 by lemille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(unsigned long n, int upper)
{
	char	buff[20];
	char	*hex;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n == 0)
	{
		ft_print_c('0');
		return (1);
	}
	while (n > 0)
	{
		buff[i++] = hex[n % 16];
		n /= 16;
	}
	while (i > 0)
		len += ft_print_c(buff[--i]);
	return (len);
}

int	ft_print_upperhex(unsigned int n)
{
	int	len;

	len = ft_put_hex((unsigned long)n, 1);
	return (len);
}

int	ft_print_lowerhex(unsigned int n)
{
	int	len;

	len = ft_put_hex((unsigned long)n, 0);
	return (len);
}
