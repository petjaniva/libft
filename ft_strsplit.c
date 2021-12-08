/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:44:36 by pniva             #+#    #+#             */
/*   Updated: 2021/12/02 08:38:06 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			++i;
		if (s[i] != c && s[i])
		{
			++count;
			while (s[i] && s[i] != c)
				++i;
		}
	}
	return (count);
}

static size_t	count_word_len(char const *s, size_t *i, char c)
{
	size_t	word_len;

	word_len = 0;
	while (s[*i] && s[*i] != c)
	{
		++*i;
		++word_len;
	}
	return (word_len);
}

static char	**build_array(char const *s, size_t word_count, char c)
{
	size_t	i;
	size_t	current_word;
	size_t	word_len;
	char	**array;

	array = malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	i = 0;
	current_word = 0;
	while (current_word < word_count)
	{
		while (s[i] == c)
			++i;
		word_len = count_word_len(s, &i, c);
		array[current_word] = ft_strsub(s, i - word_len, word_len);
		if (!array[current_word])
		{
			ft_free_ptr_array((void **)array, word_count);
			return (NULL);
		}
		++current_word;
	}
	array[current_word] = NULL;
	return (array);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	count;
	char	**res;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	res = build_array(s, count, c);
	if (!res)
		return (NULL);
	return (res);
}
