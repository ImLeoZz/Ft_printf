/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemille <lemille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:08:08 by lemille           #+#    #+#             */
/*   Updated: 2026/11/25 16:26:08 by lemille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

// Main function
int		ft_printf(const char *f, ...);

// Print str function
int		ft_print_s(char *str);
int		ft_print_c(char c);

// Print nbr function
int		ft_print_uint(unsigned int nb);
int		ft_print_int(int nb);

// Print hex
int		ft_print_lowerhex(unsigned int n);
int		ft_print_upperhex(unsigned int n);

// Print pointer
int		ft_print_p(va_list args);

#endif
