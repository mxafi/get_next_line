/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:08:44 by malaakso          #+#    #+#             */
/*   Updated: 2022/11/17 17:36:02 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	unsigned char	*p_i;
	size_t			n;

	if (count == 0 || size == 0)
	{
		return (ft_calloc(1, 1));
	}
	n = count * size;
	if (n % size || n % count)
		return (0);
	p = malloc(n);
	if (!p)
		return (0);
	p_i = p;
	while (n > 0)
	{
		*p_i = 0;
		p_i++;
		n--;
	}
	return (p);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	dst_len = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	if (dst_len == dstsize)
		return (src_len + dstsize);
	i = dst_len;
	while (src[i - dst_len] && i < dstsize - 1)
	{
		dst[i] = src[i - dst_len];
		i++;
	}
	dst[i] = '\0';
	return (src_len + dst_len);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*p;
	size_t	i;

	p = malloc(n + 1);
	if (!p)
		return (0);
	p[n] = '\0';
	i = 0;
	while (s1[i] && i < n)
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p && *p != (char)c)
		p++;
	if ((char)c != '\0' && *p == '\0')
		return (0);
	return (p);
}
