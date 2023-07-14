/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 04:26:44 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 18:39:24 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_read(char *leftxt, int fd)
{
	char	*buffer;
	int		size;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	size = 1;
	while (!ft_strchr(leftxt, '\n') && size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size] = 0;
		leftxt = ft_strjoin(leftxt, buffer);
	}
	free(buffer);
	return (leftxt);
}

char	*ft_get_line(char	*leftxt)
{
	int		i;
	char	*str;

	i = 0;
	if (!leftxt[i])
		return (NULL);
	while (leftxt[i] && leftxt[i] != '\n')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (leftxt[i] && leftxt[i] != '\n')
	{
		str[i] = leftxt[i];
		i++;
	}
	if (leftxt[i] == '\n')
		str[i++] = '\n';
	str[i] = 0;
	return (str);
}

char	*ft_stock(char *leftxt)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (leftxt[i] && leftxt[i] != '\n')
		i++;
	if (!leftxt[i])
	{
		free(leftxt);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(leftxt) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	while (leftxt[i])
		str[j++] = leftxt[i++];
	str[j] = 0;
	free(leftxt);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*leftxt;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	leftxt = ft_read(leftxt, fd);
	if (!leftxt)
		return (0);
	line = ft_get_line(leftxt);
	leftxt = ft_stock(leftxt);
	return (line);
}
