/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemille <lemille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 14:39:42 by lemille           #+#    #+#             */
/*   Updated: 2026/11/11 14:39:45 by lemille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	k;
	size_t	l;

	k = 0;
	l = 0;
	dst_len = ft_strlen(dst);
	if ((dst_len >= size))
		return (size + ft_strlen(src));
	while (dst[k])
		k++;
	while (k < (size - 1) && src[l])
		dst[k++] = src[l++];
	dst[k] = '\0';
	return (dst_len + ft_strlen(src));
}
