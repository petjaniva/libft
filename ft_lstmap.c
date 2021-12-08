/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:33:06 by pniva             #+#    #+#             */
/*   Updated: 2021/11/26 12:43:13 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	del(void *cont, size_t cont_size)
{
	(void) cont_size;
	free(cont);
	cont = NULL;
}

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!f || !lst)
		return (NULL);
	new_list = f(lst);
	lst = lst->next;
	while (lst)
	{
		new_elem = f(lst);
		if (!(new_elem))
		{
			ft_lstdel(&new_list, &del);
			return (NULL);
		}
		ft_lstadd_back(new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}
