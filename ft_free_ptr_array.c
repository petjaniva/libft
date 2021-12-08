/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ptr_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:56:41 by pniva             #+#    #+#             */
/*   Updated: 2021/11/30 09:56:31 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free_ptr_array(void **array, int ptr_count)
{
	if (!array || ptr_count <= 0)
		return ;
	while (--ptr_count)
		free(array[ptr_count]);
	free(array);
	array = NULL;
}
