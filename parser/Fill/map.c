/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 01:48:19 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/15 02:00:19 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_newline(char *str)
{
	return (str[ft_strlen(str) - 1] == '\n');
}

int	row_len(t_data *data)
{
	int		i;
	int		lenght;

	i = 0;
	lenght = 0;
	while (data->map->file[i])
	{
		if (data->map->file[i][0] == '1'
				|| data->map->file[i][0] == ' '
				|| data->map->file[i][0] == '0')
		{
			lenght++;
		}
		i++;
	}
	return (lenght);
}

void	map(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->map->row = row_len(data);
	data->map->map = malloc(sizeof(char *) * (data->map->row + 1));
	data->map->col = 0;
	if (!data->map->map)
		ft_error("Cannot allocate memory\n");
	while (data->map->file[i])
	{
		if (data->map->file[i][0] == '1'
				|| data->map->file[i][0] == ' '
				|| data->map->file[i][0] == '0')
		{
			data->map->map[j++] = ft_strndup(data->map->file[i],
					ft_strlen(data->map->file[i]) - \
					is_newline(data->map->file[i]));
			if (data->map->col < ft_strlen(data->map->map[j - 1]))
				data->map->col = ft_strlen(data->map->map[j - 1]);
		}
		i++;
	}
	data->map->map[j] = 0;
}
