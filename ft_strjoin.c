/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:43:43 by pniva             #+#    #+#             */
/*   Updated: 2021/11/29 16:45:51 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	new_s_len;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	new_s_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_s = ft_strnew(new_s_len);
	if (!new_s)
		return (NULL);
	new_s = ft_strcpy(new_s, s1);
	new_s = ft_strcat(new_s, s2);
	return (new_s);
}
