/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:34:46 by abouazi           #+#    #+#             */
/*   Updated: 2023/06/25 04:16:56 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	num_of_lines(char **av)
{
	c_map	m;

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
	c_map	m;

	m.line = num_of_lines(av);
	m.map = (char **)malloc((sizeof(char *)) * (m.line + 1));
	if (!m.map)
		return (NULL);
	m.fd = open (av[1], O_RDONLY);
	m.i = -1;
	while (++m.i < m.line)
		m.map[m.i] = get_next_line(m.fd);
	m.i = -1;
	while (++m.i < m.line - 1)
	{
		m.tmp2 = m.map[m.i];
		m.map[m.i] = ft_substr(m.tmp2, 0, ft_strlen(m.tmp2) - 1);
		free(m.tmp2);
	}
	m.i++;
	m.map[m.i] = NULL;
	if (!m.map)
		return (NULL);
	return (close(m.fd), m.map);
}
