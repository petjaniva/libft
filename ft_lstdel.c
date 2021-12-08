/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 08:50:38 by pniva             #+#    #+#             */
/*   Updated: 2021/11/15 12:29:56 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*element;
	t_list	*temp;

	if (!alst || !del)
		return ;
	element = *alst;
	while (element)
	{
		del(element->content, element->content_size);
		temp = element->next;
		free(element);
		element = temp;
	}
	*alst = NULL;
}
