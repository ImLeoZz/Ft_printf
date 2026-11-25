/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemille <lemille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:52:59 by lemille           #+#    #+#             */
/*   Updated: 2026/11/25 07:46:24 by lemille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_c(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_s(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
