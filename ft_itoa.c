/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:22:09 by pniva             #+#    #+#             */
/*   Updated: 2021/12/02 08:37:02 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	check_negativity(int *n)
{
	if (*n < 0)
	{
		*n = *n * -1;
		return (1);
	}
	return (0);
}

static char	*build_str(int n)
{
	size_t	i;
	int		is_negative;
	size_t	digit_count;
	char	*res;

	digit_count = 0;
	is_negative = check_negativity(&n);
	if (is_negative)
		++digit_count;
	i = 0;
	digit_count += ft_count_digits(n);
	res = malloc(sizeof(char) * (digit_count + 1));
	if (!res)
		return (NULL);
	res[digit_count] = '\0';
	while (n)
	{
		res[i] = n % 10 + '0';
		n /= 10;
		++i;
	}
	if (is_negative)
		res[i] = '-';
	ft_reverse_str(res, digit_count);
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = build_str(n);
	return (res);
}
