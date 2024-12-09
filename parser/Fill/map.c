/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 01:48:19 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/17 06:31:09 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_newline(char *str)
{
	return (str[ft_strlen(str) - 1] == '\n');
}

int	row_len(t_data *data)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = 0;
	while (data->map->file[i])
	{
		if (data->map->file[i][0] == '1' || data->map->file[i][0] == \
		' ' || data->map->file[i][0] == '0')
		{
			lenght++;
		}
		if (data->map->file[i][0] == '\n')
			break ;
		i++;
	}
	return (lenght);
}

int	map_player(char **map)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	c = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'W' || map[i][j] == 'E')
				c++;
			if (c > 1)
				return (0);
		}
	}
	if (c == 0)
		return (0);
	return (1);
}

int	map_fill_split(t_data *data, int i, int j)
{
	if (data->map->file[i][0] == '1' || data->map->file[i][0] == \
		' ' || data->map->file[i][0] == '0')
	{
		data->map->map[j++] = ft_strndup(data->map->file[i], \
			ft_strlen(data->map->file[i]) - \
			is_newline(data->map->file[i]));
		if (data->map->col < (int)ft_strlen(data->map->map[j - 1]))
			data->map->col = (int)ft_strlen(data->map->map[j - 1]);
	}
	return (j);
}

void	map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->map->row = row_len(data);
	data->map->map = malloc(sizeof(char *) * (data->map->row + 1));
	data->map->col = 0;
	if (!data->map->map)
		ft_error("Cannot allocate memory\n");
	while (data->map->file[i])
	{
		j = map_fill_split(data, i, j);
		i++;
	}
	data->map->map[j] = 0;
	if (map_player(data->map->map) == 0)
		ft_error("No Player in the map");
	if (check_surr(data->map->map, data->map->row) == 0)
		ft_error("Map not surrounded by walls");
}
