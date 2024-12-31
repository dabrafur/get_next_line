/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deabraha <deabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:42:48 by deabraha          #+#    #+#             */
/*   Updated: 2024/12/31 11:46:55 by deabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*free_buf(char *buf, char *read_buf)
{
	free(read_buf);
	free(buf);
	return (NULL);
}

static char	*read_line(int fd, char	*buf)
{
	char	*read_buf;
	char	*temp_line;
	int		bytes_read;

	bytes_read = 1;
	read_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buf)
		return (NULL);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_buf(buf, read_buf));
		read_buf[bytes_read] = '\0';
		temp_line = buf;
		buf = ft_strjoin(temp_line, read_buf);
		free(temp_line);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(read_buf);
	return (buf);
}

static char	*split_line(char *buf)
{
	char	*split_line;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	split_line = ft_substr(buf, 0, i + 1);
	return (split_line);
}

static char	*assemble_new_line(char *buf)
{
	char	*temp;
	int		i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	temp = ft_substr(buf, i + 1, ft_strlen(buf) - 1);
	free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*buf[1024];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf [fd])
		buf [fd] = ft_strdup("");
	buf[fd] = read_line(fd, buf [fd]);
	if (!buf [fd])
	{
		free(buf [fd]);
		return (NULL);
	}
	next_line = split_line(buf [fd]);
	buf [fd] = assemble_new_line(buf [fd]);
	return (next_line);
}
