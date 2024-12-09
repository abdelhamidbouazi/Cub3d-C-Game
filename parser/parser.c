/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:40:51 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/17 06:16:08 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	assign_colors(char *line, t_data *data, char key)
{
	int		i;
	char	**split;

	i = -1;
	split = ft_split(line, ",");
	if (key == 'C')
		rgb(&data->map->ciel, split);
	if (key == 'F')
		rgb(&data->map->floor, split);
	free_splt(split);
}

void	get_colors(char *line, t_data *data)
{
	int	i;

	i = 0;
	if (valid_color_str(line + 1) == 0)
		ft_error("Color not Valid");
	while (line[++i] == ' ' || line[i] == '\t')
		;
	assign_colors(line + i, data, line[0]);
}

void	header_check(t_data *data)
{
	if (!data->map->no || !data->map->so || !data->map->ea || !data->map->we)
		ft_error("Texture missing!!");
	if (is_texture_missing(data->map->no) || \
		is_texture_missing(data->map->so) || \
		is_texture_missing(data->map->ea) || \
		is_texture_missing(data->map->we))
	{
		ft_error("Texture not found!!");
	}
	if (!is_valid_color(data->map->ciel))
		ft_error("Ciel color should be between 0 and 255");
	if (!is_valid_color(data->map->floor))
		ft_error("Floor color should be between 0 and 255");
}

void	ft_header(t_data *data)
{
	int	i;

	i = -1;
	init_texture_color(data);
	while (data->map->file[++i])
	{
		if (data->map->file[i][0] == '\n')
			;
		else if (ft_strncmp(data->map->file[i], "NO ", 3) == 0 || \
		ft_strncmp(data->map->file[i], "SO ", 3) == 0 || \
		ft_strncmp(data->map->file[i], "WE ", 3) == 0 || \
		ft_strncmp(data->map->file[i], "EA ", 3) == 0)
		{
			get_texture(data->map->file[i], data->map);
		}
		else if (ft_strncmp(data->map->file[i], "C ", 2) == 0 || \
		ft_strncmp(data->map->file[i], "F ", 2) == 0)
			get_colors(data->map->file[i], data);
	}
	header_check(data);
}

void	parser(char **arg, t_data *data)
{
	int	i;

	i = -1;
	if (extension(arg[1]))
		ft_error("Check File Name !");
	data->map->fd = open(arg[1], O_RDONLY);
	if (data->map->fd == -1)
		ft_error("Opening file error !");
	data->map->file = read_map(arg);
	ft_header(data);
	map(data);
	player(data);
}
