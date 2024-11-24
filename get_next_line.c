/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:18:10 by onajem            #+#    #+#             */
/*   Updated: 2024/11/24 12:18:58 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void freee(void *p)
{
    free(p);
    p = NULL;
}


char *get_buff(int fd, char *buff)
{
    char *dest;
    ssize_t len;
    
    len = 0;
    dest = NULL;
    while (1)
    {
        len = read(fd, buff, BUFFER_SIZE);
        if (len > 0)
            buff[len] = '\0';
        if (len == -1)
        {
            freee(dest);
            return (NULL);
        }
        if (len == 0)
            break;
        dest = ft_strjoin(dest, buff);
        if (ft_strchr(dest, '\n') || len == 0)
            break;
    }
    return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[len] = '\0';
	return (dest);
}

char *get__line(char *src, char **left)
{
    char *dest;
    int i;  
    
    i = 0;
    while (src[i] && src[i] != '\n')
        i++;
    dest = malloc(i + 1);
    if (!dest)
        return (NULL);
    i = 0;
    while (src[i] != '\n' && src[i])
    {
        dest[i] = src[i];
        i++;
    }
    i++;
    *left = ft_substr(src, i, ft_strlen(src) - i);
    dest[i - 1] = '\n';
    dest[i] = '\0';
    return (dest);
}

char *get_next_line(int fd)
{
    char *buff;
    static char *left;
    char *dest;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
        return (NULL);
    buff = malloc((size_t)BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    line = ft_strdup(left);
    left = NULL;
    dest = get_buff(fd, buff);
    freee(buff);
    if (!buff)
        return (NULL);
    line = ft_strjoin(line , get__line(dest, &left));
    return (freee(dest), freee(buff), line);
}

void gg()
{
    system("leaks a.out");
}
int main()
{
    atexit(gg);
    int fd = open("test.txt", O_RDONLY | O_RDWR, 0777);
    
    char *d = get_next_line(fd);
    printf("%s", d);
    free(d);
    
    char *dd = get_next_line(fd);
    printf("%s", dd);
    free(dd);

    char *ddd = get_next_line(fd);
    printf("%s", ddd);
    free(ddd);
    char *dddd = get_next_line(fd);
    printf("%s", dddd);
    free(dddd);
    char *ddddd = get_next_line(fd);
    printf("%s", ddddd);
    free(ddddd);    
//     char *dddddd = get_next_line(fd);
//     printf("%s", dddddd);
}
