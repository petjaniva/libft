/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:20:04 by pniva             #+#    #+#             */
/*   Updated: 2022/05/03 12:02:32 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//an implemention of quicksort algorithm for int arrays
//with starting the pivot from the last index of the array

#include "libft.h"

static int	partition(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			++i;
			ft_intswap(&array[i], &array[j]);
		}
		++j;
	}
	ft_intswap(&array[i + 1], &array[high]);
	return (i + 1);
}

void	ft_quicksort(int *array, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		ft_quicksort(array, low, pivot -1);
		ft_quicksort(array, pivot + 1, high);
	}
}
