/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:24:57 by gaguado-          #+#    #+#             */
/*   Updated: 2020/11/30 13:03:03 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

int		read_file(char **file, int fd)
{
	int		readstate;
	char	*buffer;
	char	*temptofree;

	readstate = 1;
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!(ft_strchr(file[fd], '\n')) && readstate != 0)
	{
		if ((readstate = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			ft_free(buffer);
			return (-1);
		}
		buffer[readstate] = '\0';
		temptofree = file[fd];
		file[fd] = ft_strjoin(file[fd], buffer);
		(temptofree) ? ft_free(temptofree) : NULL;
	}
	ft_free(buffer);
	if (readstate == 0)
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*fileread[4096];
	char		*temptofree;
	int			readstate;
	int			ctonl;

	ctonl = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if ((readstate = read_file(fileread, fd)) == -1)
		return (-1);
	while (fileread[fd][ctonl] != '\0' && fileread[fd][ctonl] != '\n')
		ctonl++;
	*line = ft_substr(fileread[fd], 0, ctonl);
	temptofree = fileread[fd];
	fileread[fd] = ft_substr(fileread[fd], ctonl + 1, ft_strlen(fileread[fd]));
	(temptofree) ? ft_free(temptofree) : NULL;
	if (readstate == 0)
	{
		free(fileread[fd]);
		fileread[fd] = NULL;
		return (0);
	}
	return (1);
}
