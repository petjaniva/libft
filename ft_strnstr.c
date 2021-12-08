/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:09:32 by pniva             #+#    #+#             */
/*   Updated: 2021/11/15 12:37:49 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		ndl_len;

	i = 0;
	ndl_len = ft_strlen(needle);
	if (!ndl_len)
		return ((char *)haystack);
	while (haystack[i] && (i + ndl_len - 1) < len)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp(&haystack[i], needle, ndl_len) == 0)
				return ((char *) &haystack[i]);
		}
		++i;
	}
	return (NULL);
}
