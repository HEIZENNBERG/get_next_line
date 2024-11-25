/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:59:00 by onajem            #+#    #+#             */
/*   Updated: 2024/11/25 17:19:06 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	freee(char **s)
{
	free(*s);
	*s = (NULL);
}

char	*get_left(char *left)
{
	char	*result;
	int		i;

	i = 0;
	if (!left)
		return (NULL);
	while (left[i] && left[i] != '\n')
		i++;
	if (left[i] == '\0')
		return (freee(&left), NULL);
	i++;
	result = ft_strdup(left + i);
	return (freee(&left), result);
}

char	*get__line(char *buff)
{
	char	*dest;
	int		i;
	int		j;

	if (!buff || !*buff)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
		return (ft_strdup(buff));
	i++;
	dest = malloc(i + 1);
	if (!dest)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dest[j] = buff[j];
		j++;
	}
	dest[i - 1] = '\n';
	dest[i] = '\0';
	return (dest);
}

char	*allocate(size_t size)
{
	char	*buf;

	buf = malloc(size + 1);
	if (!buf)
		return (NULL);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*left[OPEN_MAX];
	char		*buf;
	char		*line;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buf = allocate(BUFFER_SIZE);
	while (1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)
			return (freee(&buf), freee(&left[fd]), NULL);
		buf[len] = '\0';
		left[fd] = ft_strjoin(left[fd], buf);
		if (ft_strchr(left[fd], '\n') || len == 0)
			break ;
	}
	if (!left[fd])
		return (NULL);
	line = get__line(left[fd]);
	left[fd] = get_left(left[fd]);
	return (freee(&buf), line);
}
