/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemille <lemille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:08:08 by lemille           #+#    #+#             */
/*   Updated: 2026/11/24 10:57:23 by lemille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>

// Getter
size_t	ft_gettype(char *percent);

// Print function
int		ft_print_c(char c);
int		ft_printf(const char *f, ...);

#endif
