/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:38:43 by pniva             #+#    #+#             */
/*   Updated: 2021/11/15 12:35:23 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	target;

	target = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == target)
		{
			return ((char *)&s[i]);
		}
		++i;
	}
	if (s[i] == target)
		return ((char *)&s[i]);
	else
		return (NULL);
}
