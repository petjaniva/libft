/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:50:55 by pniva             #+#    #+#             */
/*   Updated: 2021/12/01 14:50:09 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_trim(char c)
{
	if ((c == ' ' || c == '\n' || c == '\t'))
		return (1);
	else
		return (0);
}

static char	*trim(char const *s)
{
	int		i;
	char	*new_s;
	int		word_begins;
	int		word_ends;

	i = 0;
	while (is_trim(s[i]))
		++i;
	word_begins = i;
	i = ft_strlen(s) - 1;
	while (is_trim(s[i]) && i >= 0)
		--i;
	word_ends = i;
	if (word_begins >= word_ends)
		return ("");
	new_s = ft_strsub(s, word_begins, word_ends - word_begins + 1);
	if (!new_s)
		return (NULL);
	return (new_s);
}

char	*ft_strtrim(char const *s)
{
	if (!s)
		return (NULL);
	return (trim(s));
}
