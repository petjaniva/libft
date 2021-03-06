/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:07:29 by pniva             #+#    #+#             */
/*   Updated: 2021/12/29 10:42:05 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *) malloc(size + 1);
	if (str)
	{
		return ((char *)ft_memset(str, '\0', size + 1));
	}
	else
		return (NULL);
}
