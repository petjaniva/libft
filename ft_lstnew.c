/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:10:01 by pniva             #+#    #+#             */
/*   Updated: 2021/12/29 10:39:35 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	if (!content)
	{
		element->content = NULL;
		element->content_size = 0;
	}
	else
	{
		element->content = malloc(content_size);
		ft_memcpy(element->content, content, content_size);
		element->content_size = content_size;
	}
	element->next = NULL;
	return (element);
}
