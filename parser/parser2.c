/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 06:01:59 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/17 06:18:34 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_texture(char *line, t_map *map)
{
	int		i;
	char	key[3];

	i = -1;
	while (++i < 2)
		key[i] = line[i];
	key[2] = '\0';
	assign_texture(key, line + i + 1, map);
}

char	*ft_trim(char *str)
{
	int	i;

	if (!str)
		ft_error("ERROR");
	i = ft_strlen(str);
	while (str[--i] == ' ')
		str[i] = '\0';
	return (str);
}

void	init_texture_color(t_data *data)
{
	data->map->no = NULL;
	data->map->so = NULL;
	data->map->ea = NULL;
	data->map->we = NULL;
	data->map->ciel.r = -1;
	data->map->floor.r = -1;
}

int	split_func(char *color, int i, int *c, int *count)
{
	if (color[i] == ',')
	{
		count++;
		if ((*(count) == 2 && i - *(c) == 1) || *(count) > 2)
			return (0);
		if ((color[i - 1] < '0' || color[i - 1] > '9') && \
			(color[i + 1] < '0' || color[i + 1] > '9'))
			return (0);
		*c = i;
		return (1);
	}
	else if (color[i] < '0' || color[i] > '9')
		return (0);
	return (1);
}

int	valid_color_str(char *color)
{
	int	i;
	int	c;
	int	count;

	i = 0;
	c = 0;
	count = 0;
	color = ft_trim(color);
	while (color[++i] == ' ' || color[i] == '\t')
		;
	while (color[++i])
		split_func(color, i, &c, &count);
	return (1);
}
