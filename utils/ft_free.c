/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:18:07 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/17 05:33:02 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data->map);
	free(data->ray);
	free(data->keys);
}
