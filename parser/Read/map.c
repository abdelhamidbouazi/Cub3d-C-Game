/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:34:46 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 18:37:30 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	num_of_lines(char **av)
{
	t_map	m;

	m.i = 0;
	m.fd = open(av[1], O_RDONLY);
	while (1)
	{
		m.tmp = get_next_line(m.fd);
		free(m.tmp);
		if (!m.tmp)
			break ;
		m.i++;
	}
	return (close(m.fd), m.i);
}

char	**read_map(char	**av)
{
	t_map	m;

	m.line = num_of_lines(av);
	m.file = (char **)malloc((sizeof(char *)) * (m.line + 1));
	if (!m.file)
		return (NULL);
	m.fd = open (av[1], O_RDONLY);
	m.i = -1;
	while (++m.i < m.line)
		m.file[m.i] = get_next_line(m.fd);
	m.i = -1;
	while (++m.i < m.line - 1)
	{
		m.tmp2 = m.file[m.i];
		m.file[m.i] = ft_substr(m.tmp2, 0, ft_strlen(m.tmp2) - 1);
		free(m.tmp2);
	}
	m.i++;
	m.file[m.i] = NULL;
	if (!m.file)
		return (NULL);
	return (close(m.fd), m.file);
}
