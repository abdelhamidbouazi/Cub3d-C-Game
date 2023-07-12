/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:46:53 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/11 08:27:13 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int move(t_data *data)
{
	if(data->keys->forward == true)
	{
		forward(data);
		mlx_clear_window(data->mlx, data->win);
		raycasting(data);
	}
	if(data->keys->back == true)
	{
		back(data);
		mlx_clear_window(data->mlx, data->win);
		raycasting(data);
	}
	if(data->keys->left == true)
	{
		left(data);
		mlx_clear_window(data->mlx, data->win);
		raycasting(data);
	}
	if(data->keys->right == true)
	{
		right(data);
		mlx_clear_window(data->mlx, data->win);
		raycasting(data);
	}
	if(data->keys->rotate_left == true)
	{
		rotate_left(data);
		mlx_clear_window(data->mlx, data->win);
		raycasting(data);
	}
	if(data->keys->rotate_right == true)
	{
		rotate_right(data);
		mlx_clear_window(data->mlx, data->win);
		raycasting(data);
	}
	if (data->keys->esc == true)
		esc();
	return 0;
}
