/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 09:42:32 by pniva             #+#    #+#             */
/*   Updated: 2021/11/08 13:00:48 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*res;
	int		i;

	i = 0;
	len = ft_strlen(s);
	res = (char *) malloc (sizeof(*res) * (len + 1));
	if (res)
	{
		while (s[i])
		{
			res[i] = s[i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	else
		return (NULL);
}
