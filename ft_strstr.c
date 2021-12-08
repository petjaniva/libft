/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 07:55:47 by pniva             #+#    #+#             */
/*   Updated: 2021/11/18 13:00:20 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		ndl_len;

	i = 0;
	ndl_len = ft_strlen(needle);
	if (!ndl_len)
		return ((char *)haystack);
	while (haystack[i])
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
