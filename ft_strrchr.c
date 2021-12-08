/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:08:57 by pniva             #+#    #+#             */
/*   Updated: 2021/11/18 14:10:39 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	int		i;
	char	target;

	target = (char) c;
	s_len = ft_strlen(s);
	i = s_len;
	while (i >= 0)
	{
		if (s[i] == target)
		{
			return ((char *)&s[i]);
		}
		--i;
	}
	return (NULL);
}
