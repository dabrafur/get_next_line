/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deabraha <deabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:38:58 by deabraha          #+#    #+#             */
/*   Updated: 2024/12/31 10:58:39 by deabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf)
		buf = ft_strdup("");
	buf = read_line(fd, buf);
	if (!buf)
	{
		free(buf);
		return (NULL);
	}
	next_line = split_line(buf);
	buf = assemble_new_line(buf);
	return (next_line);
}
