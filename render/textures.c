/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 07:01:45 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 07:02:04 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void texture(t_data *data)
{
	int	h;
	int	w;
	// (void)data;
	data->image.img_window = mlx_xpm_file_to_image(data->mlx, "xpm/so.xpm", &w, &h);
	if (!data->image.img_window)
		exit(0);
	data->image.so = (int *)mlx_get_data_addr(data->image.img_window,
			&data->image.bit_pixel, &data->image.line_len, &data->image.endian);
	data->image.img_window = mlx_xpm_file_to_image(data->mlx, "xpm/ea.xpm", &w, &h);
	if (!data->image.img_window)
		exit(0);
	data->image.no = (int *)mlx_get_data_addr(data->image.img_window,
			&data->image.bit_pixel,
			&data->image.line_len,
			&data->image.endian);
	data->image.img_window = mlx_xpm_file_to_image(data->mlx, "xpm/no.xpm", &w, &h);
	if (!data->image.img_window)
		exit(0);
	data->image.we = (int *)mlx_get_data_addr(data->image.img_window,
			&data->image.bit_pixel,
			&data->image.line_len,
			&data->image.endian);
	data->image.img_window = mlx_xpm_file_to_image(data->mlx,"xpm/we.xpm", &w, &h);
	if (!data->image.img_window)
		exit(0);
	data->image.ea = (int *)mlx_get_data_addr(data->image.img_window,
			&data->image.bit_pixel,
			&data->image.line_len,
			&data->image.endian);

}
