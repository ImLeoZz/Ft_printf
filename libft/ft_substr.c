/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemille <lemille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:34:54 by lemille           #+#    #+#             */
/*   Updated: 2026/11/12 17:50:05 by lemille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	s_len;
	size_t	size;

	s_len = ft_strlen(s);
	if (s_len <= start)
	{
		dest = malloc(1);
		dest[0] = '\0';
		return (dest);
	}
	size = ft_min(len, (s_len - start));
	dest = malloc(size + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, &s[start], size);
	dest[size] = '\0';
	return (dest);
}
