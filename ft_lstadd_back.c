/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:52:16 by pniva             #+#    #+#             */
/*   Updated: 2021/11/25 09:52:35 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list *head, t_list *elem_to_add)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem_to_add;
}
