/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 07:58:36 by pniva             #+#    #+#             */
/*   Updated: 2021/11/29 16:49:44 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new_s;
	size_t	s_len;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	new_s = ft_strnew(s_len);
	if (!new_s)
		return (NULL);
	while (s[i])
	{
		new_s[i] = f(s[i]);
		++i;
	}
	return (new_s);
}
