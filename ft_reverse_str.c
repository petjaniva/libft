/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:45:58 by pniva             #+#    #+#             */
/*   Updated: 2021/12/02 08:35:15 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse_str(char *str, size_t len)
{
	size_t	i;
	char	temp;
	size_t	last_digit;

	last_digit = len - 1;
	i = 0;
	while (i < last_digit)
	{
		temp = str[i];
		str[i] = str[last_digit];
		str[last_digit] = temp;
		++i;
		--last_digit;
	}
}
