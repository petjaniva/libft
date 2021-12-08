/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:47:45 by pniva             #+#    #+#             */
/*   Updated: 2021/11/25 09:48:11 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_digits(int n)
{
	size_t	digit_count;

	digit_count = 0;
	while (n)
	{
		n /= 10;
		++digit_count;
	}
	return (digit_count);
}
