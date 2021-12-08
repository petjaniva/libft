/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:23:07 by pniva             #+#    #+#             */
/*   Updated: 2021/11/18 12:40:41 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	i;
	size_t	bytes_to_cpy;

	dst_len = ft_strlen(dst);
	i = 0;
	if (size > dst_len)
		bytes_to_cpy = size - dst_len;
	else
		return (size + ft_strlen(src));
	while (src[i] && i < bytes_to_cpy - 1)
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}
