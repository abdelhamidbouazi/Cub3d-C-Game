/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 07:01:45 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 19:13:26 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	texture_so_and_ea(t_data *data)
{
	int	h;
	int	w;

	data->image.img_window = mlx_xpm_file_to_image(data->mlx, \
		data->map->so, &w, &h);
	if (!data->image.img_window)
		exit(0);
	data->image.so = (int *)mlx_get_data_addr(data->image.img_window,
			&data->image.bit_pixel, &data->image.line_len, &data->image.endian);
	data->image.img_window = mlx_xpm_file_to_image(data->mlx, \
		data->map->ea, &w, &h);
	if (!data->image.img_window)
		exit(0);
	data->image.no = (int *)mlx_get_data_addr(data->image.img_window,
			&data->image.bit_pixel,
			&data->image.line_len,
			&data->image.endian);
}

void	texture_no_and_we(t_data *data)
{
	int	h;
	int	w;

	data->image.img_window = mlx_xpm_file_to_image(data->mlx, \
		data->map->no, &w, &h);
	if (!data->image.img_window)
		exit(0);
	data->image.we = (int *)mlx_get_data_addr(data->image.img_window,
			&data->image.bit_pixel,
			&data->image.line_len,
			&data->image.endian);
	data->image.img_window = mlx_xpm_file_to_image(data->mlx, \
		data->map->we, &w, &h);
	if (!data->image.img_window)
		exit(0);
	data->image.ea = (int *)mlx_get_data_addr(data->image.img_window,
			&data->image.bit_pixel,
			&data->image.line_len,
			&data->image.endian);
}
