/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:52:23 by pniva             #+#    #+#             */
/*   Updated: 2021/12/29 11:00:28 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_realloc(void **ptr, size_t old_size, size_t new_size)
{
	void *temp;

	temp = malloc(new_size);
	if (!temp)
		return (0);
	ft_memcpy(temp, *ptr, old_size);
	free(*ptr);
	*ptr = temp;
	return (new_size);
}
