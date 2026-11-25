/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemille <lemille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:08:08 by lemille           #+#    #+#             */
/*   Updated: 2026/11/25 07:50:58 by lemille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>

// Main function
int		ft_printf(const char *f, ...);

// Print function
int		ft_print_s(char *str);
int		ft_print_int(int nb);
int		ft_print_c(char c);

#endif
