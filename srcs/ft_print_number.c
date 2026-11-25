/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemille <lemille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 07:45:20 by lemille           #+#    #+#             */
/*   Updated: 2026/11/25 07:46:15 by lemille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(long int nb)
{
	size_t	k;

	k = 1;
	if (nb < 0)
	{
		nb *= -1;
		k++;
	}
	while (nb > 9)
	{
		nb /= 10;
		k++;
	}
	return (k);
}

int	ft_print_int(int nb)
{
	ft_putnbr_fd(nb, 1);
	return (ft_intlen(nb));
}
