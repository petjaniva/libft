/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:18:15 by pniva             #+#    #+#             */
/*   Updated: 2022/01/06 09:19:29 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_mallocs(char **memory, char **buffer)
{
	if (memory)
		free(*memory);
	if (buffer)
		free(*buffer);
	return (-1);
}

static int	cleanup(char **memory, char **buffer, int read_res)
{
	free(*buffer);
	if (read_res < 0)
		return (-1);
	if (read_res == 0 && ft_strlen(*memory) == 0)
	{
		ft_memdel((void **)memory);
		return (0);
	}
	else
		return (1);
}

static char	*get_and_remove_line_from_memory(char **memory)
{
	size_t	i;
	char	*line;
	char	*temp;

	i = 0;
	while ((*memory)[i] && (*memory)[i] != '\n')
		++i;
	line = malloc(sizeof(*line) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while ((*memory)[i] && (*memory)[i] != '\n')
	{
		line[i] = (*memory)[i];
		++i;
	}
	line[i] = '\0';
	temp = ft_strsub(*memory, i + 1, ft_strlen(*memory) - i);
	free(*memory);
	*memory = temp;
	return (line);
}

static int	read_to_memory(const int fd, char **memory)
{
	char	*buffer;
	int		read_res;
	char	*temp;

	buffer = ft_memalloc(BUFF_SIZE + 1);
	if (!buffer)
	{
		return (free_mallocs(memory, NULL));
	}
	read_res = 1;
	while (read_res > 0 && !ft_strchr(*memory, '\n'))
	{
		read_res = read(fd, buffer, BUFF_SIZE);
		if (read_res >= 0)
			buffer[read_res] = '\0';
		temp = ft_strjoin(*memory, buffer);
		if (!temp)
		{
			return (free_mallocs(memory, &buffer));
		}
		free(*memory);
		*memory = temp;
	}
	return (cleanup(memory, &buffer, read_res));
}

int	ft_get_next_line(const int fd, char **line)
{
	static char	*memory[MAX_FD];
	int			read_success;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || fd >= MAX_FD)
		return (-1);
	if (!memory[fd])
	{
		memory[fd] = ft_memalloc(BUFF_SIZE + 1);
		if (!memory[fd])
			return (-1);
	}
	read_success = read_to_memory(fd, &memory[fd]);
	if (read_success > 0)
	{
		*line = get_and_remove_line_from_memory(&memory[fd]);
		if (!line)
		{
			free(memory[fd]);
			return (-1);
		}
	}
	return (read_success);
}
