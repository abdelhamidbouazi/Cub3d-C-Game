/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 00:32:48 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/17 05:30:29 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_start_view(t_data *data)
{
	if (data->map->view_direction == 'N')
		data->player.angle = 3 * M_PI / 2;
	else if (data->map->view_direction == 'S')
		data->player.angle = M_PI / 2;
	else if (data->map->view_direction == 'W')
		data->player.angle = M_PI;
	else
		data->player.angle = 0;
}

void	init_player(t_data *data)
{
	data->ray = (t_ray *)malloc(sizeof(t_ray));
	if (data->ray == NULL)
		return ;
	player_start_view(data);
	data->player.x = (data->player.x * 40) + 20;
	data->player.y = (data->player.y * 40) + 20;
	data->player.fov = M_PI / 3;
}

void	textures_(t_data *data)
{
	texture_so_and_ea(data);
	texture_no_and_we(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error("Arguments Number Error!");
	data.map = (t_map *)malloc(sizeof(t_map));
	if (!data.map)
		return (0);
	parser(av, &data);
	init_player(&data);
	data.keys = (t_keys *)malloc(sizeof(t_keys));
	if (data.keys == NULL)
		return (0);
	init_keys(data.keys);
	data.wall_width = WALL_WIDTH;
	data.wall_height = WALL_HEIGHT;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	mlx_hook(data.win, 2, 0L, press, &data);
	mlx_hook(data.win, 3, 0L, release, &data);
	mlx_hook(data.win, 17, 1L, esc, &data);
	textures_(&data);
	raycasting(&data);
	mlx_loop_hook(data.mlx, move, &data);
	mlx_loop(data.mlx);
	ft_free(&data);
}
