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

static char	*cut_line(char *buf)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	new_line = ft_substr(buf, 0, i + 1);
	return (new_line);
}

static char	*new_line(char *buf)
{
	int		i;
	char	*temp;

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
	static char	*buf;
	char		*line;

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
	line = cut_line(buf);
	buf = new_line(buf);
	return (line);
}
