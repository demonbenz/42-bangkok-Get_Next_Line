/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:54:12 by otangkab          #+#    #+#             */
/*   Updated: 2022/11/15 20:05:56 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_str_extract(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (!src[i])
		return (NULL);
	while (src[i] && src[i] != '\n')
		i++;
	dest = (char *)malloc((i + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] && src[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

char	*ft_stradd(char *stash, char *buffer)
{
	char	*s;

	if (!stash)
	{
		stash = malloc(1);
		stash[0] = '\0';
		if (!stash)
			return (0);
	}
	s = ft_strjoin(stash, buffer);
	free(stash);
	return (s);
}

char	*ft_stash_clean(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	free(str);
	return (line);
}

char	*ft_read_line(int fd, char *stash)
{
	ssize_t	ret;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		return (0);
	}
	ret = 1;
	while ((ret != 0) && (!ft_strchr(stash, '\n')))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ret] = '\0';
		stash = ft_stradd(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	stash[fd] = ft_read_line(fd, stash[fd]);
	if (!stash[fd])
	{
		return (NULL);
	}
	line = ft_str_extract(stash[fd]);
	stash[fd] = ft_stash_clean(stash[fd]);
	return (line);
}
